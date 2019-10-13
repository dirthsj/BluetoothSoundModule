#pragma once

#include <ArduinoJson.h>
#include <HTTPClient.h>

class OpenWeatherMap {
    public:
        OpenWeatherMap(HTTPClient& client);
        void fetchData();
        float getLon();
        float getLat();
        uint16_t getWeatherId();
        String getWeatherMain();
        String getDescription();
        String getIcon();
        String getBase();
        float getTemp();
        int getPressure();
        float getHumidity();
        float getTempMin();
        float getTempMax();
        int getVisibility();
        float getWindSpeed();
        uint16_t getWindDeg();
        float getWindGust();
        uint16_t getCloudsAll();
        uint16_t getDt();
        uint8_t getSysType();
        uint16_t getSysId();
        String getCountry();
        uint16_t getSunrise();
        uint16_t getSunset();
        int getTimezone();
        uint16_t getId();
        String getName();
        uint8_t getCod();
    private:
        const static int SIZE = 800;
        const String baseUrl = "https://api.openweathermap.org/data/2.5/weather";
        const String apiToken = "c75f9e0d3dc55a7ac15e64e129f4046b";
        StaticJsonDocument<SIZE> doc;
        HTTPClient& client;
};
