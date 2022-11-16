# Créé par sarah theoulle, le 22/08/2022 en Python 3.7
import requests

import csv  #This action requires the 'csv' module
import time

#-------------------
pagination_cursor=[""]      #list of all the pagination cursor


#---------------------
row_list = [[ "Streamer_follower_login"]]

#--------------Pour les requetes curl
headers = {
    'Client-ID': '***',
    'Authorization': '***',
}

params = {
    'to_id': '***',   #entrer l'ID de la personne dont on veut recuperer les followers *
    'first': '100',
    'after': "",
}

while pagination_cursor[len(pagination_cursor)-1] != None:          #allows to get every pages of followers (100 followers per request)

#-------------------------requete curl
    r = requests.get('https://api.twitch.tv/helix/users/follows', params=params, headers=headers)       #request to the API
    response_json= r.json()                        #json file

#-----------------------stockage du cursor temp
    pagination_temp =response_json.get("pagination")
    if pagination_temp != None :

        cursor_temp=pagination_temp.get("cursor")
        pagination_cursor.append(cursor_temp)
        params["after"]=cursor_temp
    else :
        pagination_cursor.append("stop")

#-----------------------stockage de la premiere page de datas
    response_json =response_json.get("data")        #recuperer uniquement les datas
    for i in range(0,len(response_json)):           #parcourir chaque follow du compte
        ligne=[]                                #liste a enregistrer dans le csv
        ident= response_json[i].get("from_id") #recuperer le login du follow
        ligne.append(ident)               #ajout a la liste pour le csv des 4 valeurs
        login= response_json[i].get("from_login") #recuperer le login du follow
        ligne.append(login)
        row_list.append(ligne)
    print([len(pagination_cursor)-1])
    #time.sleep(0.1)



# And then use the following to create the csv file:
with open('followers_streamer.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(row_list)
# This will create a csv file in the current directory
