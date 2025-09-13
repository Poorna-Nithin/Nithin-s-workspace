# from flask_ngrok import run_with_ngrok
from flask import Flask
from flask import Flask, app, request
import json

from base64 import b64decode, b64encode
from flask_cors import CORS, cross_origin
import requests

app = Flask(__name__)
cors = CORS(app)
# run_with_ngrok(app)   #starts ngrok when the app is run
@app.route('/covid', methods=['GET','POST'])
def a():
    # img = request.values.get('uri')
    # print(img)
    img = request.json['uri']
    # x = [str(i) for i in img]
    # img = ','.join(x)
    # print(img, type(img))
    r = requests.post("https://3525-35-222-177-229.ngrok-free.app/covid", data={'uri':img})
    return r.json()
    
if __name__ == '__main__':
    app.run(host="0.0.0.0", debug=True)