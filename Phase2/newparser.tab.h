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
#define	IF	263
#define	SWITCH	264
#define	CASE	265
#define	DEFAULT	266
#define	FOR	267
#define	WHILE	268
#define	DO	269
#define	BREAK	270
#define	CONTINUE	271
#define	CONST_TYPE	272
#define	INT_TYPE	273
#define	FLOAT_TYPE	274
#define	BOOL_TYPE	275
#define	STRING_TYPE	276
#define	FUNCTION	277
#define	PRINT	278
#define	RETURN	279
#define	IFX	280
#define	ELSE	281
#define	ENDLINE	282
#define	OR	283
#define	AND	284
#define	GREATER_EQUAL	285
#define	LESS_EQUAL	286
#define	EQUAL	287
#define	NOTEQUAL	288
#define	NOT	289
#define	NEGATIVE	290


extern YYSTYPE yylval;
