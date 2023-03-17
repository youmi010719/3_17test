# LAB1 Implementation of Lexical Analyzer

## Grammar Settings
G[\<Word Symbol\>] --> \<Identifier\> $\epsilon$ | \<Unsigned Int\> $\epsilon$ | \<Single Char\> $\epsilon$ | \<Double Char\> $\epsilon$  

\<Identifier\> --> [a-z A-Z] | \<Identifier\>[a-z A-Z] | \<Identifier\>[0-9]

\<Unsigned Int\> --> [0-9] | \<Unsigned Int\>[0-9]

\<Single Char\> --> + | - | * | ; | , | ( | ) | { | } | %

\<Double Char\> --> \<Greater-than\>= | \<Less-than\>= | \<Less-than\>> | \<Not\>= | \<Equal\>= | \<Divide\>* | \<Add\>+︱\<Add\>=︱\<Minus\>-︱\<Minus\>=︱\<Multiple\>=︱\<Divide\>=︱\<Greater-than\>>︱\<Less-than\><︱\<And\>&︱\<Or\>|︱\<Divide\>/︱\<Multiple\>/

\<Less Than\> --> <
\<Equal\> --> =
\<Greater-than\> --> >
\<Divide\> --> /
\<Not\> --> !
\<Add\> --> +
\<Minus\> --> -
\<Multiple\> --> *
\<And\> --> &
\<Or\> --> |

## Categorical Codes
| Word Symbol | Categorical Code | Word Symbol | Categorical Code |
|---|---|---|---|
|Identifier|1|}|24|
|Unsigned Int|2|>|25|
|void|3|<|26|
|int|4|=|27|
|float|5|!|28|
|double|6|/|29|
|if|7|>=|30|
|else|8|<=|31|
|for|9|!=|32|
|do|10|==|33|
|while|11|%|34|
|return|12|++|35|
|break|13|--|36|
|+|14|+=|37|
|-|15|-=|38|
|*|16|*=|39|
|;|17|/=|40|
|,|18|>>|41|
|(|19|<<|42|
|)|20|&&|43|
|[|21|\|\||44|
|]|22|\||45|
|{|23|&|46|
| | |/*|47|
| | |*/|48|
| | |//|49|