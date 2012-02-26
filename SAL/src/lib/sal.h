#ifndef SAL_H
#define SAL_H
struct SQL_RSET_STRUCT {
		void *resultSet;
		int index;
		char **data;
		int nfields;
};
typedef struct SQL_RSET_STRUCT* SQL_RSET;
typedef char **SQL_ROW;
// SAL Public API
int SQL_connect(const char *dbhost,
 const char *dbuser,
 const char *dbpassword,
 const char *dbname);
 SQL_RSET SQL_query(const char *queryText);
 int SQL_free(SQL_RSET resultSet);
 SQL_ROW SQL_fetch_row(SQL_RSET resultSet);
#endif

