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

INSERT INTO circuits (circuit_id, nom, pays, nombre_de_tours, longueur_circuit, longueur_course, type_circuit, niveau_difficulte, usure_pneus, virages_gauche, virages_droite, longueur_ligne_droite, zones_drs) VALUES
    (1, 'Circuit international de Sakhir', 'Bahreïn', 56, 5.412, 308.238, 'Permanent', 2, 3, 6, 12, 1090, 2),
    (2, 'Autodromo Enzo e Dino Ferrari', 'Italie', 63, 4.909, 309.049, 'Permanent', 2, 3, 9, 9, 760, 2),
    (3, 'Algarve International Circuit', 'Portugal', 66, 4.653, 306.826, 'Permanent', 2, 5, 6, 9, 900, 2),
    (4, 'Circuit de Barcelona-Catalunya', 'Espagne', 66, 4.675, 308.424, 'Permanent', 2, 3, 7, 10, 821, 1),
    (5, 'Circuit de Monaco', 'Monaco', 78, 3.337, 260.286, 'Urbain', 4, 5, 6, 8, 530, 1),
    (6, 'Baku City Circuit', 'Azerbaïdjan', 51, 6.003, 306.049, 'Urbain', 3, 3, 12, 8, 2000, 2),
    (7, 'Circuit Paul Ricard', 'France', 53, 5.842, 309.690, 'Permanent', 2, 2, 11, 9, 1087, 2),
    (8, 'Red Bull Ring', 'Autriche', 71, 4.318, 306.452, 'Permanent', 1, 2, 3, 7, 650, 1),
    (9, 'Silverstone Circuit', 'Royaume-Uni', 52, 5.891, 306.198, 'Permanent', 2, 3, 8, 10, 770, 2),
    (10, 'Hungaroring', 'Hongrie', 70, 4.381, 306.670, 'Permanent', 2, 1, 4, 14, 626, 2),
    (11, 'Circuit de Spa-Francorchamps', 'Belgique', 44, 7.004, 308.176, 'Montagne', 5, 3, 9, 11, 2015, 2),
    (12, 'Circuit de Zandvoort', 'Pays-Bas', 72, 4.259, 306.144, 'Permanent', 1, 3, 6, 9, 423, 1),
    (13, 'Autodromo Nazionale di Monza', 'Italie', 53, 5.793, 306.720, 'Permanent', 2, 1, 4, 7, 1120, 2),
    (14, 'Circuit urbain de Sotchi', 'Russie', 53, 5.848, 309.45, 'Permanent', 1, 1, 8, 12, 1100, 2),
    (15, 'Intercity Istanbul Park', 'Turquie', 58, 5.338, 309.396, 'Permanent', 5, 3, 8, 6, 1000, 2),
    (16, 'Circuit des Amériques', 'États-Unis', 56, 5.513, 308.405, 'Permanent', 2, 3, 11, 9, 970, 2),
    (17, 'Autódromo Hermanos Rodríguez', 'Mexique', 71, 4.304, 305.354, 'Permanent', 1, 5, 4, 7, 650, 2),
    (18, 'Autódromo José Carlos Pace', 'Brésil', 71, 4.309, 305.909, 'Permanent', 2, 4, 7, 5, 530, 2),
    (19, 'Jeddah Corniche Circuit', 'Arabie saoudite', 50, 6.174, 308.700, 'Urbain', 5, 3, 11, 7, 1114, 2),
    (20, 'Yas Marina Circuit', 'Émirats arabes unis', 58, 5.554, 305.355, 'Permanent', 2, 4, 9, 11, 1141, 2);

CREATE TABLE IF NOT EXISTS `f1_project`.`drivers` (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nom VARCHAR(20) NOT NULL,
    courses INT,
    victoires INT,
    deuxiemes INT,
    troisiemes INT,
    podiums INT,
    poles INT,
    laps INT,
    points FLOAT,
    equipe VARCHAR(50)
);

INSERT INTO drivers (nom, courses, victoires, deuxiemes, troisiemes, podiums, poles, laps, points, equipe) VALUES
    ('Max Verstappen', 22, 10, 8, 0, 18, 10, 1211, 395.5, 'Red Bull Racing'),
    ('Lewis Hamilton', 22, 8, 8, 1, 17, 5, 1269, 387.5, 'Mercedes'),
    ('Valtteri Bottas', 22, 1, 1, 9, 11, 4, 1134, 226, 'Mercedes'),
    ('Sergio Pérez', 22, 1, 0, 4, 5, 0, 1186, 190, 'Red Bull Racing'),
    ('Daniel Ricciardo', 22, 1, 0, 0, 1, 0, 1267, 115, 'McLaren'),
    ('Esteban Ocon', 22, 1, 0, 0, 1, 0, 1153, 74, 'Alpine'),
    ('Carlos Sainz', 22, 0, 1, 3, 4, 0, 1294, 164.5, 'Ferrari'),
    ('Lando Norris', 22, 0, 1, 3, 4, 1, 1223, 160, 'McLaren'),
    ('Charles Leclerc', 22, 0, 1, 0, 1, 2, 1145, 159, 'Ferrari'),
    ('Pierre Gasly', 22, 0, 0, 1, 1, 0, 1074, 110, 'AlphaTauri'),
    ('Fernando Alonso', 22, 0, 0, 1, 1, 0, 1258, 81, 'Alpine'),
    ('Sebastian Vettel', 22, 0, 1, 0, 1, 0, 1263, 43, 'Aston Martin'),
    ('Lance Stroll', 22, 0, 0, 0, 0, 0, 1170, 34, 'Aston Martin'),
    ('Yuki Tsunoda', 22, 0, 0, 0, 0, 0, 1080, 32, 'AlphaTauri'),
    ('George Russell', 22, 0, 1, 0, 1, 0, 1142, 16, 'Williams'),
    ('Nicholas Latifi', 22, 0, 0, 0, 0, 0, 1191, 7, 'Williams'),
    ('Antonio Giovinazzi', 22, 0, 0, 0, 0, 0, 1255, 3, 'Alfa Romeo Racing'),
    ('Nikita Mazepin', 22, 0, 0, 0, 0, 0, 1009, 0, 'Haas'),
    ('Mick Schumacher', 22, 0, 0, 0, 0, 0, 1136, 0, 'Haas'),
    ('Kimi Raikkonen', 20, 0, 0, 0, 0, 0, 1061, 10, 'Alfa Romeo Racing');
