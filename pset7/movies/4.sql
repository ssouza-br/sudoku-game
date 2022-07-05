SELECT COUNT(*) FROM movies JOIN (SELECT * FROM ratings WHERE rating=10.0) ON id=movie_id;


SELECT title FROM movies JOIN (SELECT rating FROM ratings) ON id=movie_id;