SELECT COUNT(title)
FROM movies
JOIN ratings on id = ratings.movie_id
WHERE rating = 10;