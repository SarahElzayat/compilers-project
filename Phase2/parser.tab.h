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
#define	VARIABLE	261
#define	IF	262
#define	SWITCH	263
#define	CASE	264
#define	DEFAULT	265
#define	FOR	266
#define	WHILE	267
#define	DO	268
#define	BREAK	269
#define	CONTINUE	270
#define	CONST	271
#define	INT_TYPE	272
#define	FLOAT_TYPE	273
#define	BOOL_TYPE	274
#define	STRING_TYPE	275
#define	FUNCTION	276
#define	PRINT	277
#define	RETURN	278
#define	IFX	279
#define	ELSE	280
#define	ENDLINE	281
#define	OR	282
#define	AND	283
#define	GREATER_EQUAL	284
#define	LESS_EQUAL	285
#define	EQUAL	286
#define	NOTEQUAL	287
#define	NOT	288
#define	NEGATIVE	289


extern YYSTYPE yylval;
