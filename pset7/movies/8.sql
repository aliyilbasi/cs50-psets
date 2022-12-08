-- list of all names of Toy Story

SELECT name 
FROM people JOIN stars ON  stars.person_id = people.id
    JOIN movies ON movies.id = stars.movie_id
    WHERE title = 'Toy Story';