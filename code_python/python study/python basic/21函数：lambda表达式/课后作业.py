print(list(filter(lambda x : not(x%3),range(1,100))))
print([i for i in range(1,100) if not(i%3)])
print(list(zip([1,3,5,7,9],[2,4,6,8,10])))
print(list(map(lambda x, y : [x, y], [1, 3, 5, 7, 9], [2, 4, 6, 8, 10])))
