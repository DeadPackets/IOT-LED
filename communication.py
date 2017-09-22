import sys
import serial
import os
from time import sleep
from pubnub.callbacks import SubscribeCallback
from pubnub.pubnub import PubNub, SubscribeListener
from pubnub.enums import PNStatusCategory
from pubnub.pnconfiguration import PNConfiguration
from pubnub.pubnub import PubNub
from pubnub.enums import PNOperationType, PNStatusCategory

pnconfig = PNConfiguration() 
pnconfig.subscribe_key = 'sub-c-dbe312e4-896d-11e7-99f6-f65693608d5b'
pnconfig.publish_key = 'pub-c-9eea524c-18c5-41ae-a88e-3329adee616c' 
pubnub = PubNub(pnconfig)
channel = 'led-matrix'


ser = serial.Serial('/dev/cu.usbmodem1411', 9600)


class MySubscribeCallback(SubscribeCallback):
    def status(self, pubnub, status):
        pass
    
    def presence(self, pubnub, presence):
        pass  # handle incoming presence data
 
    def message(self, pubnub, message):
    	print(message.message)
    	ser.write(message.message.encode())
    	
      

pubnub.add_listener(MySubscribeCallback())
pubnub.subscribe().channels(channel).execute()


