#include <Arduino.h>

const float soundSpeed = 0.0343;

void ultraSonicSensorSetup(int ultraSonicVoutPin, int trigPin, int echoPin)
{
	pinMode(ultraSonicVoutPin, OUTPUT);
	digitalWrite(ultraSonicVoutPin, HIGH);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

float getDistanceFromUltraSonicSensor(int trigPin, int echoPin)
{
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	long duration = pulseIn(echoPin, HIGH);
	float distanceCm = duration * soundSpeed / 2;
	return distanceCm;
}

void buzz(int buzzerPin, int repeat)
{
	for (int i = 0; i < repeat; i++) {
		digitalWrite(buzzerPin, HIGH);
		delay(150);
		digitalWrite(buzzerPin, LOW);
		delay(150);
	}
}