#pragma once

#include "Base.h"
#include "pch.h"

#include "DBObjects/Table.h"
#include "DBObjects/Record.h"
#include "DBObjects/Field.h"


namespace QRD
{

	/**
	* Struct holding all tables and their corresponding records
	*/
	struct DbData
	{
		Table table;
		std::vector<Record> records;
	};


	class QRD_API Database
	{
	public:
		Database(const std::string& filePath);

		/**
		* Creates a new table, adds it to m_Data
		*
		* @param tableName is the name the table will have
		* @returns the newly created table
		*/
		Table& CreateTable(const std::string& tableName);

		/**
		* Finds the table by name
		* 
		* @param tableName is the name of the table to search for
		* @returns the found table, empty table object if not found
		*/
		Table& GetTable(const std::string& tableName);

		/**
		* Deletes the table
		*
		* @param table is the table to delete
		*/
		void DeleteTable(const Table& table);

		/**
		* Deletes the table
		*
		* @param tableName is the table's name
		*/
		void DeleteTable(const std::string& tableName);

		/**
		* Reads database stored in file into memory
		*/
		void ReadDb();

		/**
		* Writes the database stored in memory to file
		*/
		void WriteDb();

		/**
		* Writes everything stored in memory to file and destroys all database object in memory
		*/
		void ExitDb();


		/************************************************************************************
		*****************           DEBUG FUNCTIONS AND VARIABLES           *****************
		************************************************************************************/
		auto& GetData() const { return m_Data; }

	private:
		

	private:
		
		/**
		* Datastructure holding all tables and their corresponding records
		*/
		std::vector<DbData*> m_Data;
		
		/**
		* File path to the .dbs file
		*/
		const std::string& m_DBFilePath;
	};
}


