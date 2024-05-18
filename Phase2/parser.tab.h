typedef union {
  int intValue;                          /* integer  */
  float floatValue;                      /* double   */
  char* stringValue;                     /* string   */
  bool boolValue;                        /* boolean  */

  char *sIndex;                       /* symbol table index */
  char *varType;                      /* variable type      */
  Node *nodePtr;                      /*   node             */
} YYSTYPE;
#define	INTEGER	257
#define	FLOAT	258
#define	STRING	259
#define	BOOL	260
#define	VARIABLE	261
#define	IF	262
#define	SWITCH	263
#define	CASE	264
#define	DEFAULT	265
#define	SWITCH_BODY	266
#define	FOR	267
#define	WHILE	268
#define	DO	269
#define	REPEAT	270
#define	BREAK	271
#define	CONTINUE	272
#define	CONST	273
#define	INT_TYPE	274
#define	FLOAT_TYPE	275
#define	BOOL_TYPE	276
#define	STRING_TYPE	277
#define	VOID_TYPE	278
#define	DECLARE_ONLY	279
#define	FUNCTION	280
#define	PRINT	281
#define	RETURN	282
#define	BLOCK	283
#define	IFX	284
#define	ELSE	285
#define	FUNC	286
#define	OR	287
#define	AND	288
#define	GREATER_EQUAL	289
#define	LESS_EQUAL	290
#define	EQUAL	291
#define	NOT_EQUAL	292
#define	NOT	293
#define	NEGATIVE	294


extern YYSTYPE yylval;
