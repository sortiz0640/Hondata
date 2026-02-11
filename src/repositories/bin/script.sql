CREATE DATABASE db_hondata;
USE db_hondata;

CREATE TABLE Manufacturer (

    id                  INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
    name                VARCHAR(200) NOT NULL,
    legalName           VARCHAR(250) NOT NULL,
    globalSlogan        VARCHAR(500) NOT NULL,
    foundationCountry   VARCHAR(250) NOT NULL,
    foundationYear      INT NOT NULL

)

CREATE TABLE EngineSpecification (

    id              INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
    configuration   VARCHAR(100) NOT NULL,
    fuel            VARCHAR(50) NOT NULL,
    power           VARCHAR(50) NOT NULL,
    torque          VARCHAR(50) NOT NULL,
    compression     VARCHAR(50) NOT NULL,
    hasVTEC         BIT NOT NULL,
    idManufacturer  INT NOT NULL

    FOREIGN KEY (idManufacturer) REFERENCES Manufacturer(id)
    
)

CREATE TABLE EngineInstance (

    id              INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
    condition       VARCHAR(50) NOT NULL,
    mileage         INT NOT NULL,
    operatingHours  INT NOT NULL,
    isOperative     BIT NOT NULL,    
    hasOverhaul     BIT NOT NULL,
    idEngineSpecification INT NOT NULL

    FOREIGN KEY (idEngineSpecification) REFERENCES EngineSpecification(id)

)


CREATE TABLE Model (

    id              INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
    name            VARCHAR(100) NOT NULL,
    bodywork        VARCHAR(150) NOT NULL,
    segment         VARCHAR(150) NOT NULL,
    generation      VARCHAR(200) NOT NULL,
    wheeldrive      VARCHAR(100) NOT NULL,
    releaseYear     INT NOT NULL,
    idManufacturer  INT NOT NULL

    FOREIGN KEY (idManufacturer) REFERENCES Manufacturer(id)
)



CREATE TABLE Car (

    id                  INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
    color               VARCHAR(50) NOT NULL,
    transmission        VARCHAR(50) NOT NULL,
    idModel             INT NOT NULL,
    idEngineInstance    INT NOT NULL UNIQUE

    FOREIGN KEY (idModel)          REFERENCES Model(id),
    FOREIGN KEY (idEngineInstance) REFERENCES EngineInstance(id)

)

ALTER TABLE Car 
ADD CONSTRAINT FK_Car_Engine
FOREIGN KEY (idEngineInstance) REFERENCES EngineInstance(id)
ON DELETE CASCADE;

