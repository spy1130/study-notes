from __future__ import absolute_import, division, print_function
import traceback,pygame,sys,time,win32gui # win32gui --> pywin32
from pygame.locals import *
from itertools import cycle
from pathlib import Path
import random as r

BLINK_EVENT = TIME_EVENT = pygame.USEREVENT + 0

class Hero_Cube(pygame.sprite.Sprite):

    '''创建hero的类并初始化属性,再定义移动方法'''

    def __init__(self,bg_size,n):
        pygame.sprite.Sprite.__init__(self)
        if n:
            self.image=player_font.render('民',True,(255,120,60))
        else:
            self.image=player_font.render('党',True,(255,0,0))
        self.rect=self.image.get_rect()
        self.hero_width,self.hero_height=bg_size[0],bg_size[1]
        self.rect.left,self.rect.top=r.randint(0,self.hero_width-10),r.randint(0,self.hero_height-10)
        self.speed=4

    def moveUp(self):
        if self.rect.bottom>0:
            self.rect.top-=self.speed
        else:
            self.rect.top=self.hero_height
    
    def moveDown(self):
        if self.rect.top<self.hero_height:
            self.rect.top+=self.speed
        else:
            self.rect.bottom=0
    def moveLeft(self):
        if self.rect.right>0:
            self.rect.left-=self.speed
        else:
            self.rect.left=self.hero_width

    def moveRight(self):
        if self.rect.left<self.hero_width:
            self.rect.left+=self.speed
        else:
            self.rect.right=0

class Food_Cube(pygame.sprite.Sprite):

    '''创建food的类并初始化属性,再定义刷新方法'''

    def __init__(self,bg_size,group):
        pygame.sprite.Sprite.__init__(self)
        self.image=food_font.render(r.choice(['建党','斗争','钉钉子','劳动','奋斗','奉献','创造','主动','节约','战斗','社会主义法治','人民首创']),True,(125,125,125))
        self.rect=self.image.get_rect()
        self.food_width,self.food_height=bg_size[0],bg_size[1]
        while pygame.sprite.spritecollide(self,group,False):
            self.rect.left,self.rect.top=r.randint(0,self.food_width-10),r.randint(0,self.food_height-10)
        self.exist=True

    def reset(self,group):
        self.image=food_font.render(r.choice(['建党','斗争','钉钉子','劳动','奋斗','奉献','创造','主动','节约','战斗','社会主义法治','人民首创']),True,(125,125,125))
        self.rect=self.image.get_rect()
        group.remove(self)
        while pygame.sprite.spritecollide(self,group,False):
            self.rect.left,self.rect.top=r.randint(0,self.food_width-10),r.randint(0,self.food_height-10)
        group.add(self)
        self.exist=True

class Devil_Cube(pygame.sprite.Sprite):

    '''创建devil的类并初始化属性,再定义移动方法'''

    def __init__(self,bg_size,color,position=[r.randint(0,940),r.randint(0,520),r.randint(0,940),r.randint(0,520)]):
        pygame.sprite.Sprite.__init__(self)
        if color:
            self.image=food_font.render(r.choice(['贪污','垄断','技术瓶颈','文化断层','贫富差距']),True,(255,255,255))
        else:
            self.image=food_font.render(r.choice(['压迫','战争','歧视','污蔑','抵制','挑战']),True,(0,0,0))
        self.rect=self.image.get_rect()
        self.devil_width,self.devil_height=bg_size[0],bg_size[1]
        self.rect.left,self.rect.top=r.randint(0,self.devil_width-self.rect.width),r.randint(0,self.devil_height-self.rect.height)
        while ((position[0]-120<self.rect.left<position[0]+140) and (position[1]-120<self.rect.top<position[1]+140)) or ((position[2]-120<self.rect.left<position[2]+140) and (position[3]-120<self.rect.top<position[3]+140)):
            self.rect.left,self.rect.top=r.randint(0,self.devil_width-self.rect.width),r.randint(0,self.devil_height-self.rect.height) # 设置在生存模式下的刷新范围
        self.speed=r.randint(0,2)
    
    def move(self,position):
        self.x=position[0]-self.rect.left
        self.y=position[1]-self.rect.top
        if self.x and self.y: # 根据与hero在xy轴上的距离差,调整devil移动方向
            self.rect=self.rect.move((abs(self.x)//self.x)*self.speed,(abs(self.y)//self.y)*self.speed)
        elif not self.x:
            self.rect=self.rect.move(0,(abs(self.y)//self.y)*self.speed)
        elif not self.y:
            self.rect=self.rect.move((abs(self.x)//self.x)*self.speed,0)

    def judge(self,positions): # 完全就是两点间距离公式
        self.x_1=positions[0]-self.rect.left
        self.y_1=positions[1]-self.rect.top
        self.x_2=positions[2]-self.rect.left
        self.y_2=positions[3]-self.rect.top
        if self.x_1*self.x_1+self.y_1*self.y_1>self.x_2*self.x_2+self.y_2*self.y_2:
            return positions[2],positions[3]
        else:
            return positions[0],positions[1]

    def reset(self,position): # 定义刷新位置
        while ((position[0]-120<self.rect.left<position[0]+140) and (position[1]-120<self.rect.top<position[1]+140)) or ((position[2]-120<self.rect.left<position[2]+140) and (position[3]-120<self.rect.top<position[3]+140)):
            self.rect.left,self.rect.top=r.randint(0,self.devil_width-self.rect.width),r.randint(0,self.devil_height-self.rect.height)

def gradual_change(images,seconds=15): # 用于转场时渐变覆盖的效果 
    for e in range(35):
        for image in images:
            screen.blit(image,images[image])
        pygame.display.flip()
        pygame.time.delay(seconds)

def stop(image,mode): # 暂停显示图片
    Pause=True
    gradual_change({image:(0,0)},1)
    while Pause:
        for event in pygame.event.get():
            if event.type==QUIT:
                pygame.quit()
                sys.exit()
            if event.type==KEYDOWN:
                if event.key==K_h and not mode:
                    Pause=False
        if win32gui.GetForegroundWindow()==handle and mode:
            Pause=False

def inverted(img): # 反转图片颜色
   inv = pygame.Surface(img.get_rect().size, pygame.SRCALPHA)
   inv.fill((255,255,255,255))
   inv.blit(img, (0,0), None, BLEND_RGB_SUB)
   return inv
        

def running(): 
    
    '''游戏主程序,用于多次重新开始'''

    positions=[0,0,0,0]
    score=level=0
    Heros=pygame.sprite.Group()
    Foods=pygame.sprite.Group()
    Devils=pygame.sprite.Group()
    temp=extra=10
    hero_1=Hero_Cube(bg_size,0)
    Heros.add(hero_1)
    if not players: # 根据模式,创建P2玩家
        hero_2=Hero_Cube(bg_size,1)
        Heros.add(hero_2)
    for i in range(foods): # 实例化food
        food=Food_Cube(bg_size,Foods)
        Foods.add(food)
    with open('record.NULL','r')as f: # 获取最高纪录
        record=int(f.read())
    Tip1=tip_font.render('外患',True,(75,75,75))
    Tip2=tip_font.render('内忧',True,(175,175,175))
    Tip1.set_alpha(20)
    Tip2.set_alpha(20)
    Tips=cycle([Tip2,Tip1])
    Tip=next(Tips)
    a=Tip1.get_rect()
    print(a.width)
    best_text=number_font.render('Best: %d' % record,True,(125,125,125))
    background=background_normal
    while True:
        i=0
        for event in pygame.event.get(): # 检测退出事件
            if event.type==QUIT:
                pygame.quit()
                sys.exit()
            if event.type==TIME_EVENT: # 判断背景闪烁的时间点
                Tip,background=next(Tips),next(backgrounds)
                heartbeat_sound.play()
        screen.blit(background,(0,0))
        screen.blit(Tip,(425,85))
        if win32gui.GetForegroundWindow()!=handle: # 窗口失去焦点后暂停
            press_sound.play()
            pygame.mixer.music.pause()
            stop(pause,1)
            press_sound.play()
            pygame.mixer.music.unpause()
        my_keys=pygame.key.get_pressed()
        if players: # 根据模式,选择不同的操作模式
            if my_keys[K_s] or my_keys[K_DOWN]:
                hero_1.moveDown()
            if my_keys[K_a] or my_keys[K_LEFT]:
                hero_1.moveLeft()
            if my_keys[K_d] or my_keys[K_RIGHT]:
                hero_1.moveRight()
            if my_keys[K_w] or my_keys[K_UP]:
                hero_1.moveUp()
        else:
            if my_keys[K_s]:
                hero_1.moveDown()
            if my_keys[K_a]:
                hero_1.moveLeft()
            if my_keys[K_d]:
                hero_1.moveRight()
            if my_keys[K_w]:
                hero_1.moveUp()
            if my_keys[K_DOWN]:
                hero_2.moveDown()
            if my_keys[K_LEFT]:
                hero_2.moveLeft()
            if my_keys[K_RIGHT]:
                hero_2.moveRight()
            if my_keys[K_UP]:
                hero_2.moveUp()
        for each in Foods: # 检测各food的exist属性,判断其是否发生碰撞,以便于调用刷新方法
            if each.exist:
                screen.blit(each.image,each.rect)
            else:
                each.reset(Foods)
        for hero in Heros: # 获取玩家当前坐标
            positions[i],positions[i+1]=hero.rect.left,hero.rect.top
            screen.blit(hero.image,hero.rect)
            i+=2
        if len(Heros)==1: # 判断现存玩家个数,以便于调用judge计算距离
            for the in Devils:
                the.move(positions)
                screen.blit(the.image,the.rect)
        else:
            for the in Devils:
                the.move(the.judge(positions))
                screen.blit(the.image,the.rect)
        if hellmode: # 判断地狱模式
            for devil in Devils: # 判断devil之间是否重合,若重合则刷新位置
                Devils.remove(devil)
                coincidence=pygame.sprite.spritecollide(devil,Devils,False)
                if coincidence:
                    for single in coincidence:
                        single.reset(positions)
                Devils.add(devil)
        for heros in Heros:
            dead=pygame.sprite.spritecollide(heros,Foods,False) # 对food的碰撞检测
            if dead:
                for one in dead: # 每吃一个food,加一分,并将其exist属性改为False
                    score+=1
                    one.exist=False
            if score>=temp: # 判断分数是否触发难度机制
                temp+=extra
                level+=1
                if hellmode: # 检查当前模式是否为困难模式
                    if level%2: # 奇数生成黑块
                        devil=Devil_Cube(bg_size,True,positions)
                    else: # 偶数生成白块
                        devil=Devil_Cube(bg_size,False,positions)
                else:
                    devil=Devil_Cube(bg_size,False,positions)
                Devils.add(devil)
                generate_sound.play()
            if pygame.sprite.spritecollide(heros,Devils,False): # 对devil的碰撞检测,碰撞后将所碰撞hero删除
                death_sound.play()
                Heros.remove(heros)
        score_text=number_font.render('Score: %d' %score,True,(125,125,125))
        level_text=number_font.render('Level: %d' %level,True,(125,125,125))
        if not Heros: # 判断hero现存个数是否为0,为0则游戏结束
            if score>record: # 判断是否破纪录,并将其记录下来
                with open('record.NULL','w')as f:
                    f.write(str(score))
            
            '''以下为死亡画面初始化及模式选择'''

            screen.fill((255,255,255))
            pygame.time.delay(100)
            best=score_font.render('Best: %d' %record,True,(0,0,0))
            passage=score_font.render('Your Socre: %d' %score,True,(0,0,0))
            passage_rect=passage.get_rect()
            GameOver=over_font.render('革命尚未成功,同志还需努力',True,(0,0,0))
            GameOver_rect=GameOver.get_rect()
            GameOver.set_alpha(20)
            GameOver_rect.left,GameOver_rect.top=(bg_size[0]-GameOver_rect.width)//2,bg_size[1]//5
            passage_rect.left,passage_rect.top=(bg_size[0]-passage_rect.width)//2,GameOver_rect.bottom+20
            again_rect.left,again_rect.top=(bg_size[0]-again_rect.width)//2-100,passage_rect.bottom+50
            choose_rect.left,choose_rect.top=(bg_size[0]-choose_rect.width)//2+100,passage_rect.bottom+50
            gradual_change({GameOver:GameOver_rect})
            screen.blit(best,(10,6))
            screen.blit(passage,passage_rect)
            pygame.time.delay(250)
            pygame.display.flip()
            gradual_change({again_image:again_rect,choose_image:choose_rect})
            pygame.time.delay(250)
            pygame.display.flip()
            while True:
                keys=pygame.key.get_pressed()
                if keys[K_r]: # 按'R',重新开始
                    press_sound.play()
                    return 1
                if keys[K_ESCAPE]: # 按'Esc',重新选择
                    press_sound.play()
                    return 0
                for event in pygame.event.get():
                    if event.type==QUIT:
                        pygame.quit()
                        sys.exit()
        screen.blit(score_text,(10,6))
        screen.blit(level_text,(800,6))
        screen.blit(best_text,(10,45))
        pygame.display.flip()
        clock.tick(60)

def main():

    '''游戏外部主程序,用于初始化全局变量及模式选择'''

    global delay,handle,backgrounds,pause,foods,players,bg_size,over_font,tip_font,food_font,player_font,number_font,score_font,screen,background_normal,black,again_image,again_rect,choose_image,choose_rect,GameOver_image,GameOver_rect,clock,hellmode,generate_sound,press_sound,death_sound,heartbeat_sound
    foods=delay=100
    hellmode=0
    record_file=Path("record.NULL")
    bg_size=width,height=960,540
    pygame.init()
    pygame.mixer.init()
    screen=pygame.display.set_mode(bg_size)
    screen.fill((0,0,0))
    screen_rect=screen.get_rect()
    pygame.mixer.music.load('music\\BGM\\music.ogg')
    pygame.mixer.music.set_volume(0.2)
    generate_sound=pygame.mixer.Sound('music\\Sound effects\\generate.wav')
    generate_sound.set_volume(0.1)
    press_sound=pygame.mixer.Sound('music\\Sound effects\\Press.wav')
    press_sound.set_volume(0.3)
    death_sound=pygame.mixer.Sound('music\\Sound effects\\death.wav')
    death_sound.set_volume(0.3)
    heartbeat_sound=pygame.mixer.Sound('music\\Sound effects\\heartbeat.wav')
    heartbeat_sound.set_volume(1.0)
    tip_font=pygame.font.SysFont('华文行楷',55)
    player_font=pygame.font.SysFont('华文行楷',30)
    food_font=pygame.font.SysFont('华文行楷',20)
    over_font=pygame.font.SysFont('方正舒体',70)
    mark_font=pygame.font.Font('fonts\\Inkfree.ttf',30)
    word_font=pygame.font.Font('fonts\\方正基础像素.ttf',20)
    word_font.set_italic(True)
    first_word=word_font.render('按 任 意 键 开 始 游 戏 ...',True,(255,255,255))
    first_word.set_alpha(20)
    first_rect=first_word.get_rect()
    first_rect.left,first_rect.top=(width-first_rect.width)//2,height*0.8
    second_word=word_font.render('按 任 意 键 开 始 游 戏 ...',True,(0,0,0))
    second_word.set_alpha(20)
    words=cycle([second_word,first_word])
    word=next(words)
    number_font=pygame.font.Font('fonts\\Inkfree.ttf',40)
    score_font=pygame.font.Font('fonts\\Inkfree.ttf',55)
    hell=word_font.render('地狱难度已启用 | 极难警告！',True,(255,0,0))
    hell_rect=hell.get_rect()
    hell_rect.left,hell_rect.top=(width-hell_rect.width)//2,height*0.75
    Word=word_font.render("'R'键 —— 重新选择模式 | 'X'键 —— 启用地狱模式 | 'Enter'键 —— 开始游戏",True,(200,200,200))
    Word_rect=Word.get_rect()
    Word.set_alpha(20)
    Word_rect.left,Word_rect.top=(width-Word_rect.width)//2,height*0.85
    editon=mark_font.render('Version <1.1.4>',True,(175,175,175))
    editon_rect=editon.get_rect()
    editon.set_alpha(20)
    editon_rect.center=screen_rect.center
    editon_rect.left*=0.2
    myself=mark_font.render('By <Hualiang>',True,(175,175,175))
    myself_rect=myself.get_rect()
    myself.set_alpha(20)
    myself_rect.center=screen_rect.center
    myself_rect.left*=1.8
    pygame.display.set_caption("党")
    white=pygame.image.load("picture\\white.png").convert_alpha()
    white.set_alpha(20)
    keyhelp=pygame.image.load("picture\\help.png").convert_alpha()
    keyhelp.set_alpha(20)
    again_image=pygame.image.load("picture\\again.png").convert_alpha()
    again_rect=again_image.get_rect()
    again_image.set_alpha(20)
    choose_image=pygame.image.load("picture\\choose.png").convert_alpha()
    choose_rect=choose_image.get_rect()
    choose_image.set_alpha(20)
    pause=pygame.image.load("picture\\Pause.png").convert_alpha()
    pause.set_alpha(13)
    background_normal=pygame.image.load("picture\\background.png").convert_alpha()
    background_normal.set_alpha(60)
    background_swap=inverted(background_normal)
    background_swap.set_alpha(60)
    choosemode=pygame.image.load("picture\\choosemode.png").convert_alpha()
    choosemode.set_alpha(30)
    singlemode=pygame.image.load("picture\\singlemode.jpg").convert()
    doublemode=pygame.image.load("picture\\doublemode.jpg").convert()
    backgrounds=cycle([background_swap,background_normal])
    if not record_file.exists():
        with open('record.NULL','w')as f:
            f.write('0')
    pygame.key.set_repeat(100,100)
    pygame.time.set_timer(BLINK_EVENT,800)
    pygame.time.set_timer(TIME_EVENT,1500)
    clock=pygame.time.Clock()
    time.sleep(0.6)
    gradual_change({background_normal:(0,0)})
    time.sleep(0.3)
    gradual_change({editon:editon_rect,myself:myself_rect})
    start=True
    handle=win32gui.GetForegroundWindow()
    while start: # 初始化界面
        for event in pygame.event.get():
            if event.type==QUIT:
                pygame.quit()
                sys.exit()
            if event.type==KEYDOWN:
                start=False
            if event.type==BLINK_EVENT:
                word=next(words)
        screen.blit(word,first_rect)
        pygame.display.flip()
        clock.tick(60)
    gradual_change({white:(0,0)})
    time.sleep(0.4)
    while True:  # 开始界面
        hellmode=0
        pygame.mixer.music.fadeout(1000)
        gradual_change({choosemode:(0,0)})
        choose_1=True
        while choose_1: # 第一回合
            delay-=1
            keys=pygame.key.get_pressed()
            if keys[K_F1]: # 按'F1',单人模式
                press_sound.play()
                players=1
                choose_1=False
                picture=singlemode
                screen.blit(picture,(0,0))
                pygame.display.flip()
            if keys[K_F2]: # 按'F2',双人模式
                press_sound.play()
                players=0
                choose_1=False
                picture=doublemode
                screen.blit(picture,(0,0))
                pygame.display.flip()
            if keys[K_h] and not(delay%100): # 按'H',查看按键操作:
                press_sound.play()
                stop(keyhelp,0)
                press_sound.play()
                gradual_change({choosemode:(0,0)},1)
            for event in pygame.event.get():
                if event.type==QUIT:
                    pygame.quit()
                    sys.exit()
        picture.set_alpha(20)
        places=cycle([Word_rect,(0,0)])
        tips=cycle([Word,picture])
        place=next(places)
        tip=next(tips)
        choose_3=True
        while choose_3: # 第三回合
            keys=pygame.key.get_pressed()
            if keys[K_x] and not hellmode: # 按'X',启用地狱模式
                heartbeat_sound.play()
                hellmode=1
            if keys[K_r]: # 按'R',重新选择模式
                press_sound.play()
                choose_3=False
                picture.set_alpha(255)
            if keys[K_RETURN]: # 按'Enter',开始游戏
                press_sound.play()
                choose_3=False
                pygame.mixer.music.play(-1)
                while running(): # 用于重新开始
                    pass
                picture.set_alpha(255)
            for event in pygame.event.get():
                if event.type==QUIT:
                    pygame.quit()
                    sys.exit()
                if event.type==BLINK_EVENT:
                    tip=next(tips)
                    place=next(places)
            screen.blit(tip,place)
            if hellmode:
                screen.blit(hell,hell_rect)
            pygame.display.flip()
            clock.tick(60)

if __name__=='__main__':
    try:
        main()
    except SystemExit:
        pass
    except:
        traceback.print_exc()
        pygame.quit()
        input()
