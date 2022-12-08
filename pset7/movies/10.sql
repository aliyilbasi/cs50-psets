
SELECT COUNT(DISTINCT name)
    FROM people
    JOIN directors ON  directors.movie_id = people.id
    JOIN ratings ON directors.movie_id = ratings.movie_id
    WHERE rating >= 9.0;
    
    