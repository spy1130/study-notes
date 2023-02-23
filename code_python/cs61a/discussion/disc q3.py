def if_function(condition, true_result, false_result):
    """Return true_result if condition is a true value, and
    false_result otherwise.
    >>> if_function(True, 2, 3)
    2
    >>> if_function(False, 2, 3)
    3
    >>> if_function(3==2, 'equal', 'not equal')
    'not equal'
    >>> if_function(3>2, 'bigger', 'smaller')
    'bigger'
    """
    if condition:
        return true_result
    else:
        return false_result
def with_if_statement():
    """
    >>> result = with_if_statement()
    61A
    >>> print(result)
    None
    """
    if cond():
        return true_func()
    else:
        return false_func()
def with_if_function():
    """
    >>> result = with_if_function()
    Welcome to
    61A
    >>> print(result)
    None
    """
    return if_function(cond(), true_func(), false_func())
def cond():
    return False
def true_func():
    print("Welcome to")
def false_func():
    print("61A")
'''
这里false_func没有返回值

运行false和true的时候 执行了print

但是这两个里面没有return语句

所以实际上判断完返回值，应该是if_func(false,none，none）


运行函数的时候要先判断输入，如果输入形参是函数的话，就先运行函数，这个时候输入量就是运行这些函数的返回值
这里运行了函数，然后没有返回值
'''
