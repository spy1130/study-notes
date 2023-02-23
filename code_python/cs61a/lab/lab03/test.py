def uncuri(g):
     def h(x,y):
            return g(x)(y)
     return h
ans= uncuri(lambda x : lambda y: x *y)(6,7)
print(ans)