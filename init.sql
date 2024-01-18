CREATE DATABASE IF NOT EXISTS `f1_project`;

USE `f1_project`;

CREATE TABLE IF NOT EXISTS `f1_project`.`player` (
    `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `pilot` VARCHAR(45) NULL,
    `creation_date` DATETIME NULL,
    `score` INT NULL);

CREATE TABLE IF NOT EXISTS `f1_project`.`circuits` (
    circuit_id INT PRIMARY KEY,
    nom VARCHAR(255) NOT NULL,
    pays VARCHAR(255) NOT NULL,
    nombre_de_tours INT NOT NULL,
    longueur_circuit DECIMAL(8, 3) NOT NULL,
    longueur_course DECIMAL(8, 3) NOT NULL,
    type_circuit VARCHAR(50),
    niveau_difficulte INT,
    usure_pneus INT,
    virages_gauche INT,
    virages_droite INT,
    longueur_ligne_droite INT,
    zones_drs INT
);

INSERT INTO circuits (circuit_id, nom, pays, nombre_de_tours, longueur_circuit, longueur_course,  type_circuit, niveau_difficulte, usure_pneus, virages_gauche, virages_droite, longueur_ligne_droite, zones_drs)
VALUES
    (1, 'Baku City Circuit', 'Azerbaïdjan', 51, 6.003, 306.049, 'Urbain', 3, 3, 12, 8, 2000, 2),
    (2, 'Silverstone Circuit', 'Royaume-Uni', 52, 5.891, 306.332, 'Plein air', 4, 5, 8, 10, 875, 2),
    (3, 'Circuit de Spa-Francorchamps', 'Belgique', 44, 7.004, 308.176, 'Montagne', 5, 3, 9, 11, 2015, 2);

CREATE TABLE IF NOT EXISTS `f1_project`.`drivers` (
    id INT PRIMARY KEY AUTO_INCREMENT,
    full_name VARCHAR(100) NOT NULL,
    races_won INT DEFAULT 0,
    team VARCHAR(50)
);

INSERT INTO drivers (full_name, team, races_won) VALUES
    ('Lewis Hamilton', 'Mercedes', 8),
    ('Valtteri Bottas', 'Mercedes', 1),
    ('Max Verstappen', 'Red Bull Racing', 10),
    ('Sergio Perez', 'Red Bull Racing', 1),
    ('Lando Norris', 'McLaren', 0),
    ('Daniel Ricciardo', 'McLaren', 1),
    ('Charles Leclerc', 'Ferrari', 0),
    ('Carlos Sainz', 'Ferrari', 0),
    ('Pierre Gasly', 'AlphaTauri', 0),
    ('Yuki Tsunoda', 'AlphaTauri', 0),
    ('Fernando Alonso', 'Alpine', 0),
    ('Esteban Ocon', 'Alpine', 1),
    ('Sebastian Vettel', 'Aston Martin', 0),
    ('Lance Stroll', 'Aston Martin', 0),
    ('Kimi Raikkonen', 'Alfa Romeo', 0),
    ('Antonio Giovinazzi', 'Alfa Romeo', 0),
    ('Mick Schumacher', 'Haas', 0),
    ('Nikita Mazepin', 'Haas', 0),
    ('George Russell', 'Williams', 0),
    ('Nicholas Latifi', 'Williams', 0);
