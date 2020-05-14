# Problem 176: Say 100
import httplib2
import urllib

data = {'token': '3riQ5zfLLFIVzTsYfT7SuTQ0'}

http = httplib2.Http()
response1, content1 = http.request("http://open-abbey.appspot.com/interactive/say-100",
                                 "POST",
                                 urllib.urlencode(data),
                                 {'Content-Type': 'application/x-www-form-urlencoded'})

print 'Status: ' + response1['status']
#print response1
print content1
answer = 100 - int(content1[8:])
#print answer

data['answer'] = answer

response2, content2 = http.request("http://open-abbey.appspot.com/interactive/say-100",
                                 "POST",
                                 urllib.urlencode(data),
                                 {'Content-Type': 'application/x-www-form-urlencoded'})

print 'Status: ' + response2['status']
#print response2
print content2