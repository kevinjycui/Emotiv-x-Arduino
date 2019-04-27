import json
from websocket import create_connection
import ssl
import time
import requests

receivedData = create_connection("wss://emotivcortex.com:54321", sslopt={"cert_reqs": ssl.CERT_NONE})

def setup():
    receivedData.send(json.dumps({
    "jsonrpc": "2.0",
    "method": "authorize",
    "params": {},
    "id": 1
    }))

    token = receivedData.recv()[43:-3]
    
    receivedData.send(json.dumps({
        "jsonrpc": "2.0",
        "method": "queryHeadsets",
        "params": {},
        "id": 1
    }))

    print(receivedData.recv())

    receivedData.send(json.dumps({
        "jsonrpc": "2.0",
        "method": "createSession",
        "params": {
            "_auth": token,
            "status": "open",
            "project": "lingua"
        },
        "id": 1
    }))

    print(receivedData.recv())

    receivedData.send(json.dumps({
        "jsonrpc": "2.0",
        "method": "subscribe",
        "params": {
            "_auth": token,
            "streams": [
                "met"
            ]
        },
        "id": 1
    }))

    print(receivedData.recv())
