-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description 
FROM crime_scene_reports
WHERE month=7 AND day=28
AND street = "Humphrey Street"; 

--içinde bakery geçen ifadelere baktım

SELECT name,transcript 
FROM interviews
WHERE month=7 AND day=28
AND year = 2021 AND transcript LIKE "%bakery%";

--en erken saatteki uçuşa göre destination adını buldum


SELECT city FROM airports WHERE id = (SELECT destination_airport_id 
FROM flights
WHERE month=7 AND day=29
AND year = 2021 ORDER BY hour,minute LIMIT 1);

--atm, uçuş ve kamera gibi şeylerle ismi kesişen bir kişi çıktı

SELECT name 
FROM people JOIN bank_accounts ON  people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE month=7 AND day=28
AND year = 2021 AND atm_location = "Leggett Street"

INTERSECT

SELECT name
FROM people JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE month=7 AND day=29
AND year = 2021 AND hour = 8 AND minute = 20 

INTERSECT

SELECT name 
FROM people JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE month=7 AND day=28
AND year = 2021 AND hour = 10 AND minute > 5 AND minute < 25

INTERSECT

SELECT name 
FROM people JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day=28 AND duration <= 60 ;

--Bruce isminin ifadeden caller olduğunu bildiğimden receiver'ın adını arattım.

SELECT name 
FROM people JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE year = 2021 AND month = 7 AND day=28 AND duration <= 60 AND caller = (SELECT phone_number 
FROM people WHERE name = "Bruce" );


