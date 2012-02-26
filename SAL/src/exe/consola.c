#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "sal.h"
#include <stdio.h>
int main(int argc,char **argv)
{
		char txt[1024];
		if(argc!=5)
		{
				fprintf(stderr,"Especificar parametros de conexion:\n"
								"DBMS-host usuario password DATABASE-NAME\n");
				return 1;
		}
		fprintf(stderr,"Conectando...\n");
		if(SQL_connect(argv[1],argv[2],argv[3],argv[4])==0)
		{
				printf("La conexion fallo\n");
				return 1;
		}
		fprintf(stderr,"Conectado!\n");
		while(printf("SQL> "),fflush(stdout),fgets(txt,1024,stdin))
		{
				SQL_RSET r=SQL_query(txt);
				SQL_ROW f;
				if(r==NULL)
				{
						printf("El query fallo\n");
						return 1;
				}
				while((f=SQL_fetch_row(r)))
						printf("Primer campo: %s\n",f[0]);
				SQL_free(r);
		}
		return 0;
}

