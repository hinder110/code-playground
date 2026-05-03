import urllib.request

url = 'http://www.baidu.com'

response = urllib.request.urlopen(url)

content = response.read().decode('utf-8')

print(content)

content =response.read(5)

print(content)

content =response.readline(
)

print(content)