import array
import os
#from collections import namedtuple
symbols = '$¢£¥€¤'
beyond_ascii = [ord(s) for s in symbols if ord(s) > 127]
print(beyond_ascii)


colors = ['black', 'white']
sizes = ['S', 'M', 'L']
tshirts = [(color, size) for color in colors for size in sizes]

classmates = ['pp','ll']
anthor_cls = ['hz','zz','jh','yh']
game_com =[(classmate,anthor_cl) for classmate in classmates for anthor_cl in anthor_cls]
print (game_com)

# intresting is this 
# 列表推导式：[ord(symbol) for symbol in symbols] → 创建列：(ord(symbol) for symbol in symbols) → 创建生成器

tuple(ord(symbol) for symbol in symbols)


array.array('I', (ord(symbol) for symbol in symbols))

for tshirt in (f'{c} {s}' for c in colors for s in sizes):
    print(tshirt)

for game_com in (f'{classmate} {anthor_cl}' for classmate in classmates for anthor_cl in classmates):
    print(game_com)

# signifcont is : print (gmae_com)
#生成器表达式计算笛卡儿积

lax_coordinates = (33.9425, -118.408056)  # ➊

city, year, pop, chg, area = ('Tokyo', 2003, 32450, 0.66, 8014)  # ➋

traveler_ids = [('USA', '31195855'), ('BRA', 'CE342567'), ('ESP', 'XDA205856')]  # ➌

print("Sorted passport info:")
for passport in sorted(traveler_ids):  # ➍
    print('%s/%s' % passport)  # ➎

print("\nCountry codes:")
for country, _ in traveler_ids:  # ➏
    print(country)
python, c , perl , haskell , java ,lisp  = (2020 ,2021 ,2022 ,2023 ,2024, 2025)

classroom_computer = [('pp','r9000p'),('hz ','y7000p'),('jh ','tianxuan_4')]
for computer in sorted(classroom_computer):
   print('%s/%s' % computer)

pp_and_ll_computer = ('y9000p','r9000p')

pp , ll = pp_and_ll_computer

a , b = 1, 2

a , b = b , a

print (a,b)

_, filename = os.path.split('f/code/py')

print(filename)

a , b, *rest = range(5)

print(a,b,*rest)

like_body = range(7)

pp , ll , *rest_2 , = like_body 

#siginifcont things haven't tow * in the lift

print(pp , ll ,*rest_2)

#card  = collections.namedtuple('card',['rank','suit'])

name = "hallow_pp_and_ll"

print(name[7:])

#deck[start:stop:step]

#12：起始索引（从第 12 个元素开始，索引从 0 开始计数）

#:：省略 stop（表示直到序列末尾）

#13：步长（每隔 13 个元素取一个）

deck = [
    'A♠', '2♠', '3♠', 'K♠',  # 索引 0-12 (黑桃) 这里是有十三张牌的
    'A♥', '2♥', '3♥', 'K♥',  # 索引 13-25 (红桃)
    'A♦', '2♦', '3♦', 'K♦',  # 索引 26-38 (方片)
    'A♣', '2♣', '3♣', 'K♣'   # 索引 39-51 (梅花)
]

result = deck[3::4]
print(result)  # 输出: ['K♠', 'K♥', 'K♦', 'K♣']

mylove_gmae = "aierdenring_and_lol_and_zhilang"

print (mylove_gmae[20:1:-2])

#为的是返回一个切片，这也是切片这个概念的由来


list = [2 ,2 ,3 ,4 ,45 ,5 ,6 ]
list[1:5] = [22 ,33 ,44 ,55 ]
print (list)#这里是可以自动缩减范围的，那么会不会增加呢？
#这里给出的概念是/////自动长度调整/////

list[2:5] = []

print (list*10 + [name] )

print (str(list) + name)

my_friends = []