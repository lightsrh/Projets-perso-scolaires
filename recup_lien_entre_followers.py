# Créé par sarah theoulle, le 22/08/2022 en Python 3.7
import csv
import requests

follower_login=[]
follower_id=[]
#import le csv de followers sous forme de liste
with open('followers_Lunhaku.csv', 'r') as read_obj:
    csv_reader = csv.reader(read_obj)
    list_of_csv = list(csv_reader)

for i in range(1,len(list_of_csv)):
        follower_id.append(list_of_csv[i][0])        #creer liste uniquement des id

for i in range(1,len(list_of_csv)):
        follower_login.append(list_of_csv[i][1])     #creer liste uniquement des logins


# The basic usage is to first define the rows (ligne) of the csv file:
row_list = [[ "Lunhaku_follower_login","Follow_login"]]
#----------------------------------------------------------------
#len(follower_id_int)
for j in range(1,len(follower_login)):

    headers = {
        'Authorization': 'Bearer s56h8wpv4ic0rmwo1fa0t1jm8blrmb',
        'Client-Id': 'k5fvr05r8203peanbojpk2pbt1vzz0',
    }

    params = {
     'from_id' : follower_id[j],
     'first' : 100
    }

    r = requests.get('https://api.twitch.tv/helix/users/follows', params=params, headers=headers)
    response_json= r.json()
    response_json =response_json.get("data")        #recuperer uniquement les datas
    #print(response_json)
    for i in range(1,len(response_json)):           #parcourir chaque follow du compte  #1 car le premier nom est celui du doc csv et non pas un compte
        ligne=[]                                #liste a enregistrer dans le csv
        #ID = response_json[i].get("to_id")      #recuperer l'id du follow
        login= response_json[i].get("to_login") #recuperer le login du follow
        if login in follower_login:
            #ligne.append(follower_id_int[j])               #ajout a la liste pour le csv des 4 valeurs
            ligne.append(follower_login[j])
            #ligne.append(ID)
            ligne.append(login)
            row_list.append(ligne)
    print(j)
#--------------------------------------------------------------------------------

# And then use the following to create the csv file:
with open('lien_followers_Lunhaku.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(row_list)
# This will create a csv file in the current directory
