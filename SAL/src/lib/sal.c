#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sal.h"
#include <stdio.h>
#include <stdlib.h>
#if HAVE_MYSQL_H
#include <mysql.h>
#else
#if HAVE_MYSQL_MYSQL_H
#include <mysql/mysql.h>
#else
#error "No se encuentra header mysql.h"
#endif
#endif

// Flag estado conexion
static int connected=0;
// Result set comodin para query's sin filas que retornar
static SQL_RSET rsetComodin=NULL;
static MYSQL nhp_sal_conn;
extern MYSQL my;
int SQL_connect(const char *nhp_dbhost,
const char *nhp_dbuser,
const char *nhp_dbpassword,
const char *nhp_dbname)
{
// No se puede reconectar
if(connected==1)
return 0;
// Inicializar (por unica vez) el result set comodin
if(rsetComodin==NULL)
rsetComodin=(SQL_RSET)malloc(sizeof(struct SQL_RSET_STRUCT));
// Inicializar libreria mysqlclient
mysql_init(&nhp_sal_conn);
// Conectar a servidor
if(mysql_real_connect(&nhp_sal_conn,nhp_dbhost,
nhp_dbuser,nhp_dbpassword,nhp_dbname,0,NULL,0))
{
connected=1;
return 1;
}
connected=0;
return 0;
}
SQL_RSET SQL_query(const char *query)
{
if(!connected)
return NULL;
if(mysql_query(&nhp_sal_conn,query)==0)
{
MYSQL_RES *mysqlResultSet;
if((mysqlResultSet=mysql_store_result(&nhp_sal_conn)))
{
SQL_RSET res=
(SQL_RSET)malloc(sizeof(struct SQL_RSET_STRUCT));
res->resultSet=mysqlResultSet;
res->index=0;
res->nfields=mysql_num_fields(mysqlResultSet);
res->data=(char **)malloc(sizeof(char *)*res->nfields);
return res;
}
else
return rsetComodin;
}
else
return NULL;
}
int SQL_free(SQL_RSET res)
{
if(res==NULL)
return 1;
if(res==rsetComodin)
return 1;
if((MYSQL_RES*)res->resultSet == NULL)
return 0;
mysql_free_result((MYSQL_RES*)res->resultSet);
free(res->data);
free(res);
return 1;
}
SQL_ROW SQL_fetch_row(SQL_RSET rs)
{
if(!rs || rs==rsetComodin)
return NULL;
SQL_ROW r=mysql_fetch_row((MYSQL_RES*)rs->resultSet);
if(r==NULL)
return NULL;
int z;
for(z=0;z<rs->nfields;z++)
rs->data[z]=r[z];
return rs->data;
}
