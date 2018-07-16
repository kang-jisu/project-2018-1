-- MySQL dump 10.13  Distrib 8.0.11, for Win64 (x86_64)
--
-- Host: localhost    Database: memo
-- ------------------------------------------------------
-- Server version	8.0.11

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8mb4 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `category`
--

DROP TABLE IF EXISTS `category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `category` (
  `category` varchar(20) DEFAULT 'category1',
  `cid` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`cid`),
  UNIQUE KEY `category` (`category`)
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `category`
--

LOCK TABLES `category` WRITE;
/*!40000 ALTER TABLE `category` DISABLE KEYS */;
INSERT INTO `category` VALUES ('category1',1),('category4',29),('새로추가한카테고리',31),('카테고리2',28);
/*!40000 ALTER TABLE `category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `storyboard`
--

DROP TABLE IF EXISTS `storyboard`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `storyboard` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `category` varchar(20) DEFAULT 'category',
  `title` varchar(45) DEFAULT NULL,
  `memoinput` text,
  `important` varchar(20) DEFAULT NULL,
  `bg` varchar(20) DEFAULT NULL,
  `file` tinytext,
  `date` date DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `storyboard_ibfk_1` (`category`),
  CONSTRAINT `storyboard_ibfk_1` FOREIGN KEY (`category`) REFERENCES `category` (`category`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `storyboard`
--

LOCK TABLES `storyboard` WRITE;
/*!40000 ALTER TABLE `storyboard` DISABLE KEYS */;
INSERT INTO `storyboard` VALUES (1,'category4','나의 첫 메모','메모를 잘 하자! 수정 ','important','E1F6FA','none','2018-06-17'),(2,'category1','메모메모~','내용 없음','important','FFCDD26e','none','2018-06-17'),(3,'카테고리2','메모3','ㅋㅋㅋㅋㅋ',NULL,'FAFABE','thumbnail.jpg','2018-06-17'),(4,'새로추가한카테고리','메모입니다.','호호','none','FFFFFF','3.jpg','2018-06-17'),(5,'category1','제목없음','큐피드~','important','CCFF906e','cupid.gif','2018-06-17'),(6,'category4','ㅇㅁㄹㄴㄻㅇㄴ','ㄻㄴㅇㄻㄴㅇㄹㄴㅇㄹ','important','FAFABE','none','2018-06-17'),(7,'category1','검색카테고리1','카테고리1검색검색',NULL,'FAFABE','none','2018-06-17'),(8,'카테고리2','검색카테고리2','ㅋ',NULL,'FFCDD26e','none','2018-06-17'),(9,'category4','4에서검색','ㅎㅎ',NULL,'FAFABE','none','2018-06-17');
/*!40000 ALTER TABLE `storyboard` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-06-17 21:57:49
