-- order movies which was in directed 2010 by their ratings and if their rating are equal alphabeetically too

SELECT rating,title 
     FROM movies JOIN ratings ON movies.id = ratings.movie_id
     WHERE year = 2010 ORDER BY rating,title ;