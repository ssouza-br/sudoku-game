SELECT title FROM movies JOIN (SELECT * FROM ratings ORDER BY rating ASC) ON id=movie_id;
