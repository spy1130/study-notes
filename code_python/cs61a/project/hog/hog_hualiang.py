"""CS 61A Presents The Game of Hog."""

from dice import six_sided, four_sided, make_test_dice
from ucb import main, trace, interact

GOAL_SCORE = 100  # The goal of Hog is to score 100 points.

######################
# Phase 1: Simulator #
######################


def roll_dice(num_rolls, dice=six_sided):
    """Simulate rolling the DICE exactly NUM_ROLLS > 0 times. Return the sum of
    the outcomes unless any of the outcomes is 1. In that case, return 1.

    num_rolls:  The number of dice rolls that will be made.
    dice:       A function that simulates a single dice roll outcome.
    """
    # These assert statements ensure that num_rolls is a positive integer.
    assert type(num_rolls) == int, 'num_rolls must be an integer.'
    assert num_rolls > 0, 'Must roll at least once.'
    # BEGIN PROBLEM 1
    num, i = 0, True
    while num_rolls:
        n = dice()
        if n == 1:
            i = False
        else:
            num += n
        num_rolls -= 1
    if i:
        return num
    else:
        return 1
    # END PROBLEM 1


def picky_piggy(score):
    """Return the points scored from rolling 0 dice.

    score:  The opponent's current score.0.0142857
    """
    # BEGIN PROBLEM 2
    n = score % 6
    if n:
        dividend, divisor = 1, 70
        while n:
            dividend = dividend*10 % divisor
            n -= 1
        return dividend*10 // divisor
    else:
        return 7
    # END PROBLEM 2


def take_turn(num_rolls, opponent_score, dice=six_sided, goal=GOAL_SCORE):
    """Simulate a turn rolling NUM_ROLLS dice, which may be 0 in the case
    of a player using Picky Piggy.
    Return the points scored for the turn by the current player.

    >>> from hog import *
    >>> take_turn(2, 0, make_test_dice(4, 5, 1))
    >>> 9
    >>> take_turn(3, 0, make_test_dice(4, 6, 1))
    >>> 1
    >>> take_turn(0, 2)
    >>> 4
    >>> take_turn(0, 0)
    >>> 7

    num_rolls:       The number of dice rolls that will be made.
    opponent_score:  The total score of the opponent.
    dice:            A function that simulates a single dice roll outcome.
    goal:            The goal score of the game.
    """
    # Leave these assert statements here; they help check for errors.
    assert type(num_rolls) == int, 'num_rolls must be an integer.'
    assert num_rolls >= 0, 'Cannot roll a negative number of dice in take_turn.'
    assert num_rolls <= 10, 'Cannot roll more than 10 dice.'
    assert opponent_score < goal, 'The game should be over.'
    # BEGIN PROBLEM 3
    if num_rolls:
        return roll_dice(num_rolls,dice)
    else:
        return picky_piggy(opponent_score)
    # END PROBLEM 3


def hog_pile(player_score, opponent_score):
    """Return the points scored by player due to Hog Pile.

    player_score:   The total score of the current player.
    opponent_score: The total score of the other player.
    """
    # BEGIN PROBLEM 4
    if player_score == opponent_score:
        return player_score
    else:
        return 0
    # END PROBLEM 4


def next_player(who):
    """Return the other player, for a player WHO numbered 0 or 1.

    >>> next_player(0)
    1
    >>> next_player(1)
    0
    """
    return 1 - who


def silence(score0, score1):
    """Announce nothing (see Phase 2)."""
    return silence


def play(strategy0, strategy1, score0=0, score1=0, dice=six_sided, goal=GOAL_SCORE, say=silence):
    """Simulate a game and return the final scores of both players, with Player
    0's score first, and Player 1's score second.

    A strategy is a function that takes two total scores as arguments (the
    current player's score, and the opponent's score), and returns a number of
    dice that the current player will roll this turn.

    >>> strat0 = lambda score, opponent: opponent % 10
    >>> strat1 = lambda score, opponent: max((score // 10) - 4, 0)
    >>> s0, s1 = hog.play(strat0, strat1, score0=71, score1=80, dice=always_seven)
    >>> 75, 108

    strategy0:  The strategy function for Player 0, who plays first.
    strategy1:  The strategy function for Player 1, who plays second.
    score0:     Starting score for Player 0
    score1:     Starting score for Player 1
    dice:       A function of zero arguments that simulates a dice roll.
    goal:       The game ends and someone wins when this score is reached.
    say:        The commentary function to call at the end of the first turn.
    """
    who = 0  # Who is about to take a turn, 0 (first) or 1 (second)
    # BEGIN PROBLEM 5
    while True:
        if who:
            score1 += take_turn(strategy1(score1,score0),score0,dice,goal)
            score1 += hog_pile(score1,score0)
        else:
            score0 += take_turn(strategy0(score0,score1),score1,dice,goal)
            score0 += hog_pile(score0,score1)
    # END PROBLEM 5
    # (note that the indentation for the problem 6 prompt (***YOUR CODE HERE***) might be misleading)
    # BEGIN PROBLEM 6
        say = say(score0,score1)
        if score1 >= goal or score0 >= goal:
            break
        who = 1 -who
    # END PROBLEM 6
    return score0, score1


#######################
# Phase 2: Commentary #
#######################


def say_scores(score0, score1):
    """A commentary function that announces the score for each player."""
    print("Player 0 now has", score0, "and Player 1 now has", score1)
    return say_scores


def announce_lead_changes(last_leader=None):
    """Return a commentary function that announces lead changes.

    >>> f0 = announce_lead_changes()
    >>> f1 = f0(5, 0)
    Player 0 takes the lead by 5
    >>> f2 = f1(5, 12)
    Player 1 takes the lead by 7
    >>> f3 = f2(8, 12)
    >>> f4 = f3(8, 13)
    >>> f5 = f4(15, 13)
    Player 0 takes the lead by 2
    """
    def say(score0, score1):
        if score0 > score1:
            leader = 0
        elif score1 > score0:
            leader = 1
        else:
            leader = None
        if leader != None and leader != last_leader:
            print('Player', leader, 'takes the lead by', abs(score0 - score1))
        return announce_lead_changes(leader)
    return say


def both(f, g):
    """Return a commentary function that says what f says, then what g says.

    >>> h0 = both(say_scores, announce_lead_changes())
    >>> h1 = h0(10, 0)
    Player 0 now has 10 and Player 1 now has 0
    Player 0 takes the lead by 10
    >>> h2 = h1(10, 8)
    Player 0 now has 10 and Player 1 now has 8
    >>> h3 = h2(10, 17)
    Player 0 now has 10 and Player 1 now has 17
    Player 1 takes the lead by 7
    """
    def say(score0, score1):
        return both(f(score0, score1), g(score0, score1))
    return say


def announce_highest(who, last_score=0, running_high=0):
    """Return a commentary function that announces when WHO's score
    increases by more than ever before in the game.

    >>> f0 = announce_highest(1) # Only announce Player 1 score gains
    >>> f1 = f0(12, 0)
    >>> f2 = f1(12, 9)
    9 point(s)! That's a record gain for Player 1!
    >>> f3 = f2(20, 9)
    >>> f4 = f3(20, 30)
    21 point(s)! That's a record gain for Player 1!
    >>> f5 = f4(20, 47) # Player 1 gets 17 points; not enough for a new high
    >>> f6 = f5(21, 47)
    >>> f7 = f6(21, 77)
    30 point(s)! That's a record gain for Player 1!
    """
    assert who == 0 or who == 1, 'The who argument should indicate a player.'
    # BEGIN PROBLEM 7
    def say(score0, score1):
        if who:
            if score1 - last_score > running_high:
                print(score1 - last_score, "point(s)! That's a record gain for Player 1!")
                return announce_highest(who, score1, score1 - last_score)
            else:
                return announce_highest(who, score1, running_high)
        else:
            if score0 - last_score > running_high:
                print(score0 - last_score, "point(s)! That's a record gain for Player 0!")
                return announce_highest(who, score0, score0 - last_score)
            else:
                return announce_highest(who, score0, running_high)
    return say
    # END PROBLEM 7


#######################
# Phase 3: Strategies #
#######################


def always_roll(n):
    """Return a strategy that always rolls N dice.

    A strategy is a function that takes two total scores as arguments (the
    current player's score, and the opponent's score), and returns a number of
    dice that the current player will roll this turn.

    >>> strategy = always_roll(5)
    >>> strategy(0, 0)
    5
    >>> strategy(99, 99)
    5
    """
    def strategy(score, opponent_score):
        return n
    return strategy


def make_averaged(original_function, trials_count=1000):
    """Return a function that returns the average value of ORIGINAL_FUNCTION
    called TRIALS_COUNT times.

    To implement this function, you will have to use *args syntax, a new Python
    feature introduced in this project.  See the project description.

    >>> dice = make_test_dice(4, 2, 5, 1)
    >>> averaged_dice = make_averaged(roll_dice, 1000)
    >>> averaged_dice(1, dice)
    3.0
    """
    # BEGIN PROBLEM 8
    def calculate_average(*args):
        result = 0
        count = trials_count
        while count:
            result += original_function(*args)
            count -= 1
        return result / trials_count
    return calculate_average
    # END PROBLEM 8


def max_scoring_num_rolls(dice=six_sided, trials_count=1000):
    """Return the number of dice (1 to 10) that gives the highest average turn score
    by calling roll_dice with the provided DICE a total of TRIALS_COUNT times.
    Assume that the dice always return positive outcomes.

    >>> dice = make_test_dice(1, 6)
    >>> max_scoring_num_rolls(dice)
    1
    """
    # BEGIN PROBLEM 9
    num_rolls, max = 1, 0
    while num_rolls < 11:
        averaged_dice = make_averaged(roll_dice, trials_count) # 10-1 9-1 8-1 7-1 6-1 5-20 4-18 3-15 2-11 1-6
        value = averaged_dice(num_rolls, dice)
        if value > max:
            num, max = num_rolls, value
        num_rolls += 1
    return num
    # END PROBLEM 9


def winner(strategy0, strategy1):
    """Return 0 if strategy0 wins against strategy1, and 1 otherwise."""
    score0, score1 = play(strategy0, strategy1)
    if score0 > score1:
        return 0
    else:
        return 1


def average_win_rate(strategy, baseline=always_roll(6)):
    """Return the average win rate of STRATEGY against BASELINE. Averages the
    winrate when starting the game as player 0 and as player 1.
    """
    win_rate_as_player_0 = 1 - make_averaged(winner)(strategy, baseline)
    win_rate_as_player_1 = make_averaged(winner)(baseline, strategy)

    return (win_rate_as_player_0 + win_rate_as_player_1) / 2


def run_experiments():
    """Run a series of strategy experiments and report results."""
    six_sided_max = max_scoring_num_rolls(six_sided)
    print('Max scoring num rolls for six-sided dice:', six_sided_max)
    print('always_roll(6) win rate:', average_win_rate(always_roll(6)))

    #print('always_roll(8) win rate:', average_win_rate(always_roll(8)))
    #print('picky_piggy_strategy win rate:', average_win_rate(picky_piggy_strategy))
    print('hog_pile_strategy win rate:', average_win_rate(hog_pile_strategy))
    #print('final_strategy win rate:', average_win_rate(final_strategy))
    "*** You may add additional experiments as you wish ***"


def picky_piggy_strategy(score, opponent_score, cutoff=8, num_rolls=6):
    """This strategy returns 0 dice if that gives at least CUTOFF points, and
    returns NUM_ROLLS otherwise.
    """
    # BEGIN PROBLEM 10
    if picky_piggy(opponent_score) < cutoff:
        return num_rolls
    else:
        return 0
    # END PROBLEM 10


def hog_pile_strategy(score, opponent_score, cutoff=8, num_rolls=6):
    """This strategy returns 0 dice when this would result in Hog Pile taking
    effect. It also returns 0 dice if it gives at least CUTOFF points.
    Otherwise, it returns NUM_ROLLS.
    """
    # BEGIN PROBLEM 11
    add_score = picky_piggy(opponent_score)
    if add_score >= cutoff or hog_pile(score + add_score, opponent_score):
        return 0
    else:
        return num_rolls
    # END PROBLEM 11


def final_strategy(score, opponent_score):
    """Write a brief description of your final strategy.

    max_scoring_num_rolls(dice=six_sided, trials_count=1000): 该函数运行一个实验来确定给出一个使该回合的平均分数最大的最少滚动次数

    picky_piggy_strategy(score, opponent_score, cutoff=8, num_rolls=6): 在使用picky_piggy达到预期时,滚0

    hog_pile_strategy(score, opponent_score, cutoff=8, num_rolls=6): 在使用picky_piggy或hog_pile达到预期时,滚0
    """
    # BEGIN PROBLEM 12
    return hog_pile_strategy(score, opponent_score, cutoff=GOAL_SCORE-score,num_rolls=max_scoring_num_rolls())
    # END PROBLEM 12

##########################
# Command Line Interface #
##########################

# NOTE: Functions in this section do not need to be changed. They use features
# of Python not yet covered in the course.


@main
def run(*args):
    """Read in the command-line argument and calls corresponding functions."""
    import argparse
    parser = argparse.ArgumentParser(description="Play Hog")
    parser.add_argument('--run_experiments', '-r', action='store_true',
                        help='Runs strategy experiments')

    args = parser.parse_args()

    if args.run_experiments:
        run_experiments()
