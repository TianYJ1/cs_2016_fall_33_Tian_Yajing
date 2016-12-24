import telebot
import urllib2
import json
import pprint

bot = telebot.TeleBot("312402737:AAGSV5sWP7zXDZfaywHWdfAiwLu-Vu7j770")

@bot.message_handler(commands=['hello'])
def handle_hello(message):
    bot.reply_to(message,"hi")

@bot.message_handler(content_types=['location'])
def send_weather(message):
    lat = message.location.latitude  
    lon = message.location.longitude

    req = urllib2.Request('https://api.darksky.net/forecast/f13517bbf96189a5f831ec1d947add32/' + str(lat) + ','+str(lon))
    response = urllib2.urlopen(req)
    weather = response.read()
    parsed_string = json.loads(weather)
  #  print(parsed_string)
    f = parsed_string["currently"]["temperature"]
    c = (f - 32) * (5/9)
    bot.reply_to(message, str(c) + " C degrees\n" + str(f) + " F degrees")

@bot.message_handler(func=lambda message: True)
def echo_all(message):
    bot.reply_to(message, message.text)

bot.polling()
