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
