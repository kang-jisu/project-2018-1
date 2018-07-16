#include <stdio.h>
#include <string.h>
#include "mysql.h"
#pragma comment(lib, "libmysql.lib")
MYSQL mysql; 
MYSQL *connection = NULL;
MYSQL_RES *sql_result;
MYSQL_ROW row;
unsigned int num_fields;
int i;

int query_stat;
char id[20];
char name[20];
char dept_name[10];
char salary[10];
int main()
{
	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, "localhost", "root", "kjs425", "university", 3306, 0, 0);
	if (connection == NULL) {
		
	if (mysql_error(&mysql))
		{
			fprintf(stderr, "Error:%s\n", mysql_error(&mysql));

		}
	}
	else printf("--connection success--   ");
	printf("mysql clien version: %s\n", mysql_get_client_info());

	query_stat = mysql_query(connection, "select * from instructor");
	sql_result = mysql_store_result(connection);

	/*int num_fields = mysql_field_count(&mysql);
	printf("%d\n", num_fields);
*/

	printf("%6s %10s %12s %6s\n", "ID", "name", "dept_name", "salary");
	while ((row = mysql_fetch_row(sql_result)) != NULL)
	{

		printf("%6s %10s %12s %6s\n", row[0], row[1], row[2], row[3]);

	}
	
	mysql_free_result(sql_result);

	//query_stat = mysql_query(connection, "delete from instructor where id='95001';");
	query_stat = mysql_query(connection, "insert into instructor values('95001', 'kangjisu', 'Comp. Sci', '90000')");
	if (query_stat == 0) {
		printf("\ninsert query 수행 완료\n\n");
	}

	query_stat = mysql_query(connection, "select * from instructor");
	sql_result = mysql_store_result(connection);

	/*int num_fields = mysql_field_count(&mysql);
	printf("%d\n", num_fields);
	*/

	printf("%6s %10s %12s %6s\n", "ID", "name", "dept_name", "salary");
	while ((row = mysql_fetch_row(sql_result)) != NULL)
	{

		printf("%6s %10s %12s %6s\n", row[0], row[1], row[2], row[3]);

	}

	mysql_close(connection);
}