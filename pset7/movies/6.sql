SELECT AVG(rating) FROM ratings JOIN (SELECT * FROM movies WHERE year=2012) ON movie_id=id;
