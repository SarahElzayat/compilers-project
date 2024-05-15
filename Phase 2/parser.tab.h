typedef union
{
    int i;              /*   integer  */
    float f;            /*   integer  */
    char c;             /*   char     */
    bool b;              /*   boolean  */
    char *s;            /*   string   */
    char *v;            /*   variable type */
    char *sIdx;           /*   symbol table */
    node *n;            /*   node     */
} YYSTYPE;
#define	INTEGER	257
#define	FLOAT	258
#define	CHAR	259
#define	BOOL	260
#define	STRING	261
#define	VARIABLE	262
//#define	CONSTANT	263
#define	IF	264
#define	SWITCH	265
#define	CASE	266
#define	DEFAULT	267
#define	FOR	268
#define	WHILE	269
#define	DO	270
#define	BREAK	271
#define	CONTINUE	272
#define	CONST	273
#define	INT_TYPE	274
#define	FLOAT_TYPE	275
#define	BOOL_TYPE	276
#define	CHAR_TYPE	277
#define	STRING_TYPE	278
#define	FUNCTION	279
#define	PRINT	280
#define	RETURN	281
#define	IFX	282
#define	ELSE	283
#define	ENDLINE	284
#define	OR	285
#define	AND	286
#define	GREATER_EQUAL	287
#define	LESS_EQUAL	288
#define	EQUAL	289
#define	NOTEQUAL	290
#define	NOT	291


extern YYSTYPE yylval;
