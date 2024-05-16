typedef union
{
    int iVal;              /*   integer       */
    float fVal;            /*   float         */
    bool bVal;             /*   boolean       */
    char *strVal;          /*   string        */

    char *conName;         /*   constant      */
    char *varName;         /*   variable      */

    char *sIdx;            /*   symbol table  */

    node *n;               /*   node          */
} YYSTYPE;
#define	INTEGER	257
#define	FLOAT	258
#define	BOOL	259
#define	STRING	260
#define	CONSTANT	261
#define	VARIABLE	262
#define	STATEMENT_LIST	263
#define	IF	264
#define	SWITCH	265
#define	CASE	266
#define	DEFAULT	267
#define	FOR	268
#define	WHILE	269
#define	DO	270
#define	BREAK	271
#define	CONTINUE	272
#define	CONST_TYPE	273
#define	INT_TYPE	274
#define	FLOAT_TYPE	275
#define	BOOL_TYPE	276
#define	STRING_TYPE	277
#define	FUNCTION	278
#define	PRINT	279
#define	RETURN	280
#define	IFX	281
#define	ELSE	282
#define	ENDLINE	283
#define	OR	284
#define	AND	285
#define	GREATER_EQUAL	286
#define	LESS_EQUAL	287
#define	EQUAL	288
#define	NOTEQUAL	289
#define	NOT	290
#define	NEGATIVE	291


extern YYSTYPE yylval;
