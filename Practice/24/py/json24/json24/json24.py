import json

with open("sourse.json", "r") as file:
    data = json.load(file)

res = json.loads("[]")
print(res)
users = dict()
for temp in data:
	if(temp["task"]):
		    users[temp["userId"]] = 0
for temp in data:
	if(temp["task"]):
		    users[temp["userId"]] += 1
for temp in users.keys() :
	obj = json.loads("{}")
	obj["task_completed"] = users[temp]
	obj["userId"] = temp
	res.append(obj)
with open("res.json", "w") as file:
    json.dump(res, file)

