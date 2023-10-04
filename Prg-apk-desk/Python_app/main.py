import requests
import json
from geopy.geocoders import Nominatim
import customtkinter
from PIL import Image
import tkintermapview
from CTkMessagebox import CTkMessagebox


class App(customtkinter.CTk):
    def __init__(self):
        super().__init__()
        self.geometry("400x750")
        self.grid_columnconfigure(0, weight=1)
        self._set_appearance_mode("dark")

        self.title("Weather APP")

        self.entry_var = customtkinter.StringVar()
        self.temp = customtkinter.StringVar(value="--")
        self.windspeed = customtkinter.StringVar(value="--")
        self.winddirection = customtkinter.StringVar(value="--")
        self.weathercode = customtkinter.StringVar(value="--")

        self.image_temp = customtkinter.CTkImage(dark_image=Image.open('./files/icons8-temperatures-64.png'), size=(40, 40))
        self.image_windspeed = customtkinter.CTkImage(dark_image=Image.open('./files/icons8-windsock-64.png'), size=(40, 40))
        self.image_winddirection = customtkinter.CTkImage(dark_image=Image.open('./files/icons8-wind-direction-64.png'), size=(40, 40))
        self.image_weathercode = customtkinter.CTkImage(dark_image=Image.open('./files/icons8-weather-64.png'), size=(40, 40))

        self.label_city_name = customtkinter.CTkLabel(self, text="Nazwa miasta:", fg_color="transparent").grid(row=0, column=0, padx=0, pady=0)
        self.entry = customtkinter.CTkEntry(self, textvariable=self.entry_var).grid(row=1, column=0, padx=0, pady=0)
        self.button = customtkinter.CTkButton(self, text="OK", command=self.get_weather).grid(row=2, column=0, padx=0, pady=10)
        self.image_temp_label = customtkinter.CTkLabel(self, image=self.image_temp, textvariable=self.temp, compound="left").grid(row=3, column=0,pady=15)
        self.image_windspeed_label = customtkinter.CTkLabel(self, image=self.image_windspeed, textvariable=self.windspeed, compound="left").grid(row=4, column=0,pady=15)
        self.image_winddirection_label = customtkinter.CTkLabel(self, image=self.image_winddirection, textvariable=self.winddirection, compound="left").grid(row=5, column=0,pady=15)
        self.image_weathercode_label = customtkinter.CTkLabel(self, image=self.image_weathercode, textvariable=self.weathercode, compound="left").grid(row=6, column=0,pady=15)
        self.map_widget = tkintermapview.TkinterMapView(self, width=300, height=300, corner_radius=10)
        self.map_widget.grid(row=7,column=0)

        self.mainloop()

    def get_weather(self):
        loc = Nominatim(user_agent="GetLoc")
        location = self.entry_var.get()

        if location is None:
            getLoc = loc.geocode(location)

            self.map_widget.set_position(getLoc.latitude, getLoc.longitude, marker=True)

            req = requests.get('https://api.open-meteo.com/v1/forecast', {
                'latitude': getLoc.latitude,
                'longitude': getLoc.longitude,
                'current_weather': True,
                'hourly': 'temperature_2m,relativehumidity_2m,windspeed_10m'

            })

            open('./files/data.json', "w").write(req.text)
            data = json.loads(req.text)["current_weather"]
            self.temp.set(f'{data["temperature"]} °C')
            self.windspeed.set(f'{data["windspeed"]} Km/h')
            self.winddirection.set(f'{data["winddirection"]} °')
            self.weathercode.set(f'{data["weathercode"]} WMO')
        else:
            CTkMessagebox(title="Error", message="Proszę podać nazwę miasta", icon="cancel")


app = App()
