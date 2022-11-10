import firebase_admin
from firebase_admin import firestore
from firebase_admin import credentials
import time
from datetime import datetime
import random

# Use a service account.
cred = credentials.Certificate('serviceAccount.json')
app = firebase_admin.initialize_app(cred)
db = firestore.client()

while True:
    print("Sending data")
    current_date = datetime.now()
    date = current_date.stfrtime('%Y-%m-%d')
    hour = current_date.stfrtime('%H')
    encendido = bool(random.getrandbits(1))
    collectionName = u'sensor_1_{0}'.format(date)
    totals_ref = db.collection(collectionName).document('totals')
    totals_doc = hour_ref.get()
    totals_data = hour_doc.to_dict()
    if totals_data == None:
        totals_ref.set({
            u'total_minutos_encendido': 1 if encendido else 0,
        })
    else:
        if envendido:
            totals_ref.update({
                u'total_minutos_encendido': totals_data[u'total_minutos_encendido'] + 1,
            })

    hour_ref = db.collection(collectionName).document(hour)
    hour_doc = hour_ref.get()
    hour_data = hour_doc.to_dict()
    if hour_data == None:
        hour_ref.set({
            u'minutos_encendido': 1 if encendido else 0,
            u'minutos_apagado': 1 if not encendido else 0
        })
    else:
        if encendido:
            hour_ref.update({
                u'minutos_encendido': hour_data[u'minutos_encendido'] + 1
            })
        else:
            hour_ref.update({
                u'minutos_apagado': hour_data[u'minutos_apagado'] + 1
            })
    time.sleep(10)