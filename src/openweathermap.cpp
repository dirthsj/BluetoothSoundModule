#include "openweathermap.h"

OpenWeatherMap::OpenWeatherMap(HTTPClient& client) : client{client} {}

void OpenWeatherMap::fetchData() {
    client.begin(baseUrl + "?q=ames,us&appid=" + apiToken);
    int httpCode = client.GET();
    String payload = client.getString();
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
        Serial.println("deserializeJson failed");
        Serial.println(error.c_str());
        Serial.println(payload);
        return;
    }
    client.end();
}

float OpenWeatherMap::getLon() {
    return doc["coord"]["lon"];
}

float OpenWeatherMap::getLat() {
    return doc["coord"]["lat"];
}

uint16_t OpenWeatherMap::getWeatherId() {
    return doc["weather"][0]["id"];
}

String OpenWeatherMap::getWeatherMain() {
    return doc["weather"][0]["main"];
}

String OpenWeatherMap::getDescription() {
    return doc["weather"][0]["description"];
}

String OpenWeatherMap::getIcon() {
    return doc["weather"][0]["icon"];
}

String OpenWeatherMap::getBase() {
    return doc["base"];
}

float OpenWeatherMap::getTemp() {
    return doc["main"]["temp"];
}

int OpenWeatherMap::getPressure() {
    return doc["main"]["pressure"];
}

float OpenWeatherMap::getHumidity() {
    return doc["main"]["humidity"];
}

float OpenWeatherMap::getTempMin() {
    return doc["main"]["temp_min"];
}

float OpenWeatherMap::getTempMax() {
    return doc["main"]["temp_max"];
}

int OpenWeatherMap::getVisibility() {
    return doc["visibility"];
}

float OpenWeatherMap::getWindSpeed() {
    return doc["wind"]["speed"];
}

uint16_t OpenWeatherMap::getWindDeg() {
    return doc["wind"]["deg"];
}

float OpenWeatherMap::getWindGust() {
    return doc["wind"]["gust"];
}

uint16_t OpenWeatherMap::getCloudsAll() {
    return doc["clouds"]["all"];
}

uint16_t OpenWeatherMap::getDt() {
    return doc["dt"];
}

uint8_t OpenWeatherMap::getSysType() {
    return doc["sys"]["type"];
}

uint16_t OpenWeatherMap::getSysId() {
    return doc["sys"]["id"];
}

String OpenWeatherMap::getCountry() {
    return doc["sys"]["country"];
}

uint16_t OpenWeatherMap::getSunrise() {
    return doc["sys"]["sunrise"];
}

uint16_t OpenWeatherMap::getSunset() {
    return doc["sys"]["sunset"];
}

int OpenWeatherMap::getTimezone() {
    return doc["timezone"];
}

uint16_t OpenWeatherMap::getId() {
    return doc["id"];
}

String OpenWeatherMap::getName() {
    return doc["name"];
}

uint8_t OpenWeatherMap::getCod() {
    return doc["cod"];
}
