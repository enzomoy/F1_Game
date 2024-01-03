CREATE DATABASE IF NOT EXISTS `f1_project`;

USE `f1_project`;

CREATE TABLE IF NOT EXISTS `f1_project`.`player` (
    `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `pilot` VARCHAR(45) NULL,
    `creation_date` DATETIME NULL,
    `score` INT NULL);
