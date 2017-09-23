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
pnconfig.subscribe_key = 'sub-c-43003980-a038-11e7-8751-e66010d856a3'
pnconfig.publish_key = 'pub-c-da06a2e0-36cd-4fad-9fa6-9e663a9c3caf' 
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


