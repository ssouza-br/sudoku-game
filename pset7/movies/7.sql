SELECT title FROM movies JOIN (SELECT rating FROM ratings) ON id=movie_id;

WHERE year=2010 ORDER BY rating ASC