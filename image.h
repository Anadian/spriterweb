/*  GIMP header image file format (RGB): /Users/cameron/Documents/s/image.h  */

static unsigned int width = 64;
static unsigned int height = 64;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
static char *header_data =
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Q)$\"15&#!A(#AI+"
	"$1Q.$R!0%2)3&\"55&R=8'2E:(\"Q=(R]@)C%B*#1D*C9H+3EJ,#QM,SYO-4%R.$1T"
	".D9W/$EY/TM\\0DY^1%\"\"1U.#25:&3%B)3UJ,45V.5&\"15F*366666V>87FJ;8&R>"
	"8V^@97*C:72E:G>G;GJJ<'RM<W^O=8&R>(2U>H:W?8BZ?XN]@HZ_A9#\"AY/$BI;'"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1)#\"11&\"Q=(#AE*$!Q-"
	"$A]0%2%3&\"15&R=8'2E;(\"Q<(R]?)3%B*#-E*C9G+3EJ+SQL,CYN-$%Q-T-T.D5W"
	"/$AY/DM[04Y_0U\"!1U*#256&3%B(3EJ+45V-5%^05F*36&266V>87FJ:8&R=8V^@"
	"97*C:'2E:W:H;7FJ<'RM<GZO=(&R=X.U>H:W?8FY?XN\\@HZ_A9#!AI/$B9;&C)C)"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!A%#\"!1&\"A=(#1E*$!Q-$QY0"
	"%2%3%R15&R98'2E:'RM<(BY?)3%A)S1D*C9F+#AI+SML,3YN-$!Q-D-T.45V/$AY"
	"/DM[04U^0U\"!1E*#2%6%2U>)35J+4%V-4U^05F*36&256V:876F;8&R=8V^@97&B"
	":'.E:G:G;'FI;WNL<GZO=8&R=X.U>8:W?(BY?XN[@8Z^A)#!AI+#B97&C)?(CIO+"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1%#\"!1%\"Q='#1E*#QM,$AY/%\"%2"
	"%R15&297'\"A9'RM<(BY>)#%A)S-D*35G+#AI+SIK,3UN-#]Q-D)S.45U/$=X/DI["
	"04U^0T]`1E*#256%2U>'3EF+4%R-4UZ056&26&246F:77&F:7VN=8F^?97&A9W2D"
	":7:G;'FJ;WNL<7VN=(\"R=X.T>86V?(BY?XN[@8Z^A(^`AI/$B)7%BYC(CIK+D9S."
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1%\"!Q-$\"Q=(#1A*#QQ,$1Y/%\"!1%R-5"
	"&B56'\"A9'RI;(2U>)#!A)S)C*C5F+#=H+CIK,3UM,T!Q-D%S.$5V.T=Y/DI[0$Q]"
	"0T]`15*\"2%2%2E>(35J+4%R-4U^/56\"26&246F:77&F98&N<8FZ>97\"A9W.D:G6G"
	";'BJ;GNL<7VN=(\"Q=X*S>86V?(>Y?HJ[@8V^@Y\"`A9+#B93%BY?(CIG+D)S-DY_0"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"\"!-%\"A5&#!E*#QM,$1U/%\"!1%B)3&B56"
	"'\"A9'BI;(2U>)#!@)C)C*31E*S=I+CIK,3QN,S]P-D)S.41U.T=X/DEZ/TQ]0TY_"
	"15&\"2%2%2E>'35B*4%R-4EZ/56&25V.466:77&B97VJ<8FZ?9'\"A9W.D:76F;'BI"
	";GNL<7VN=(\"P=H*S>86V?(>X?HJ[@8R]@X^`A9+#B)3%BY?(C9G*D)S-DI[0E:'2"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!%!!Q)$\"A9'#!A)#QI,$1U.%\"!0%B)4&256'\"=8"
	"'BI;(2U=)\"]@)3)C*#1F*S=H+CIK,#QM,SYP-4%R-T1U.D=W/DEZ0$M\\0D]`1%\"\""
	"1U2$2E:'35B*3UN,45Z/5&\"15V.36F667&B97FN;8FZ>8W\"A9G*D:76F;'BH;GJK"
	"<7VN<W^Q=8&S>(2U>X>X?8FZ@(V]@X^`A9'#B)3%BY?'C9G*D)O,DI[0E:'2F*34"
	"!!!!!!!!!!!!!!!!!!!!!!!!!A)#\"15&#!=)#AI+$1U.$R!1%B)3&256'\"A8'2E;"
	"(\"Q=(B]@)C)C*#5E*S9G+3EJ,#QM,CYO-4%R-T-U.D9W/4EY/TQ\\0DY_15&!1U.$"
	"2E:&3%F)3UJ,45V.5&\"15V*466667&>87FJ<86V>8W\"@9G*C:76F:W>I;7FK<'VM"
	"<W^P=H*R>(2U>X:X?8J[@(N\\@H^_A9#\"AY3$BI;'C9G)CYO,DI[/E:#1EZ/4FJ76"
	"!!!!!!!!!!!!!!!!!!!!!A)#\"15%\"W.4#V>&!4YR,9>Y\"V>,\"6Z2#7>8\"6^1!6:)"
	"\"WB:&X6F!F^0*I:W%W67\"FF+$WB7!W.7\"&6+((NI%X&F%H6G#7F;$'F=!725$GJ?"
	"%X*A!V\"$#G>9#'B;$WR@\"&>)#&>)&'R=&8.E%(\"C$W66#'\"1\"&Z0%W^A#VV/#GR="
	"$&>'!DYR+YBX\"&2(?XR]@HZ_A)'!AY/$B9;'C)C*CYO,DI[.E*'1EZ+3F:77G*C9"
	"!!!!!!!!!!!!!!!!!A)\"\"!1%\"Q=)$'.5!DEO$6R/'8JJ&7N>&XFK#G:8\"&V.\"765"
	"\"G67\"WJ=\"7\"1&&N0#5V\"\"W*0%H.F$W.6$G66(HJL(H^P\"&R.&(6E#6R0\"G&3#7&3"
	"\"&F+!6\"##7B8\"&Z1'86G#&R-%'*2#F2'\"W\"2$GR?\"%!U#6Z/\"&^1!FZ2'HVP#G*3"
	"\"$=O$&R.'(RK%G>;@HZ_A)#\"AY/$B97&C)C)CIO+DIW.E*#1EZ+3F:76FZC8GJK;"
	"!!!!!!!!!!!!!A)#\"!1%\"Q='#1I+$7J;!V*&&8>H(H^S%X6E$G^@!V.(&8*C\"&B,"
	"#WN<#'N=\"G&3#G24$G>8(XVQ%WR>!UQ_'H6F$WJ?$H\"B!VZ0$X6D!F:)!FJ+#'F;"
	"\"W*4\"W>9$8*D#WJ=$8\"B\"6>'\"F.&#F^2$'67&WJ=\"VV/%8*B#'B;$(\"C%X:I$'R<"
	"!V*$&8>H(I\"T%WZAA)#!AY+$B97&C)C)CYK,D9W.DY_1EJ+3F:35FZ?8G:K;H*S>"
	"!!!!!!!!!1%#\"!1%\"A='#1E*#QM,%(&A\"FV/'HBJ&82E#G*3$WF;$&Z2$7Z=\"F:*"
	"$7.6\"6V2!VN/!VN.'86H#GF;!UI]%GF;#WV>%(2G\"7B;\"':6#'B:!F*%\"&Z-\"G::"
	"\"W:8(8RN$767\"W.6%8*C!F\"\"\"62(#W>9'8JI\"6.%$H\"B#WN=&H6F\"6V0#GF:%86F"
	"\"VV-'HFK%X6G\"VR-AI/#B97&C)C(CIK+D9W-DY_0E:'3F:75FJ?8G:G;H*S=HZ[@"
	"!!!!!1%\"\"!1$\"A='#!E*#QM,$AY/#7>:\"VJ.#&R.$':8$7F=#G\"2'8*D\"&6*#'\"2"
	"\"6V/#'24!W25\"7::\"'26#G&4#&>)&(2C$'68#G\"4\"&^/!F6'\"VV/!EQ_\"&6$#7B:"
	"&HNM#W\"3$&^0#7F:)92W!VV/$7R?&(:I#&^4$WJ<%7R@&XBF\"6R+\"FR/'8^P$'R?"
	"#&J+#&R.#W>:\"G*4B97&BY?(CIK+D)S.DY_0E:'3F*35FJ?8G:G:H*O=HZ[?I;'B"
	"!1!\"!Q-$\"A9'#!A*#QI,$AY/%\"!1#X\"@#&N/#724#WN<&8FL\"'\"0$'V=\"6B,&(6E"
	"#&Z0!F2%%'V=\"W67!VJ.%H.D&'N>#4YP!F6)$WZ=\"FV/!%U_&'J=$7F<#768\"&^0"
	"!VJ,#&R.$WN>#GR>$8\"B!E]_$GF='HVN#W.4%WV=\"'28\"&:,((NI%X&F%H6G#7F;"
	"$'F=!725$GJ?%X*A!V\"$#G>9#'B;$WR@\"&>)#&>)&'R=&8.E%(\"C$W66#7\"1#7\"3"
	"!Q-$\"19&#!A)#QI,$1Y.%!]0%R)3$'F:!F:)\"&^1'HRL$'&3!6>)\"FF-!VN-!VV."
	"\"FZ1\"&N/#G.3!UM_!W63$X*C$6>(\"F>&&(:H$VR,#G*5%GN<$7\"1$G*4!FZ/%'R@"
	"%X6G#G>9!FF,#7.6!VN.\"%=]'H2F%'67\"&>'%7^B$W.6$G66(HJL(H^P\"&R.&(6E"
	"#6R0\"G&3#7&3\"&F+!6\"##7B8\"&Z1'86G#&R-%'*2#F2'\"W\"2$GR?\"%!U#F^0$'.5"
	"\"A9&\"Q=)#QI+$1U-$Q]1%R)3&\"56!V>)#&Z2$'F9&&^0!T]R\"&N+#G24\"FJ,#6F,"
	"#7:7\"6.&\"'.2\"7\"5$(&D$8*C\"F>'*Y\"P#F6+$7&0%7ZC#'\"3$724#W24$WF<%86G"
	"$WB6\"D]W!V:(!W*2#7*5*Y6U%727#G\"3'(:H%GN=!UQ_'H6F$WJ?$H\"B!VZ0$X6D"
	"!F:)!FJ+#'F;\"W*4\"W>9$8*D#WJ=$8\"B\"6>'\"F.&#F^2$'67&WJ=#&V/%X.C''ZC"
	"\"QA)#AI+$1U.$Q]0%2)3&215&R=8#%E[\"F>*#G>6!U%W!W&0$GV>$'\"3#W\"3&86F"
	"\"7B:#'B7$'*5\"'*4'(:J*9BZ\"&2&$&.'\"EZ\"'(ZL\"'26\"7.2#W.6$7F=%X2H%H>I"
	"!U9V\"F*$!W>5'(>K+YR_$V&#%W>8&'F<#7>9!UM^%GF;#WV>%(2G\"7B;\"':6#'B:"
	"!F*%\"&Z-\"G::\"W:8(8RN$767\"W.6%8*C!F\"\"\"62(#W>9'8JI\"6.%$X\"C%GZA-H^S"
	"#1E+$1Q-$QY0%2)2&\"15&B98'2I:\"6>)$X&E#7B:!FR,\"'67!G&3((NM$7J;'(FL"
	"#7N?!FZ0#7&3#7F9'Y&P%W*7!4US\"6^/&(JK%X*D!6J+%GZ@#W28*9>Z&X*@#5=Z"
	"\"5M^!FB+#'J='8RM$GF;\"6B*#'&4\"G*4#G*5#&>)&(2C$'68#G\"4\"&^/!F6'\"VV/"
	"!EQ_\"&6$#7B:&HNM#W\"3$&^0#7F:)92W!VV/$7R?&(:I#&^4%'J<%WVA*(VL.H2H"
	"$!Q-$AY0%2%2%R15&R97'2E:'RQ<\"FZ/#H\"?$7>;$7J<$7B9%(*A'H2F%GV@\"WF:"
	"#7N>\"VV/\"F6)$'F:\"GJ:$G6:!V2&%86H+)F]\"V^1((2H\"6V.$GZ@%7^B\"FR-\"F\"!"
	"$7R:$'B:%H:H%'J<\"6\"#$725#7>9!VN/%H.D&'N>#4YP!F6)$WZ=\"FV/!%U_&'J="
	"$7F<#768\"&^0!VJ,#&R.$WN>#GR>$8\"B!E]_$'>;'Y*S$7B9'X>I%G^?,Y*X3X^X"
	"$QY/%2%2&\"-4&B97'\"A9'RM<(2U>\"&F-'(NJ$7>8#GF9$GF;&W^@$G^A&8FM\"727"
	"\"W26!6\"\"#&V/'XZO\"W>8$WZ?$G^A)9>[((VP\"6J+'8>I!FB*'(FK#6Z3'X.D\"5Y`"
	"'(JM\"W:9$WZA$'J<\"G\"3$7B9\"%Z\"!W63$X*C$6>(\"F>&&(:H$VR,#G*5%GN<$7\"1"
	"$G*4!FZ/%'R@%X6G#G>9!FF,#7.6!VN.\"%5['XFJ%X&A!5I]$W*6%7F>)W287Y&Z"
	"%\"%1%R-4&296'\"E:'RM<(2Y?)#!A\"725#GJ<\"5M`$'R=%8*D$6^/&(:H#7N>!FF+"
	"\"&B*!%V!&8\"@$G68\"6:+#'\"1!6J*$GN<!UZ!$'*3\"W68\"&>($'.6$G><%'Z?!VF)"
	"%WVA\"&6&$FF+\"FV/\"VB+\"723\"6^4$(&D$8*C\"F>'*Y\"P#F6+$7&0%7ZC#'\"3$724"
	"#W24$WF<%86G$WB6\"D]W!V:(!W*2#7&4,IV]&'29\"VJ.\"G23#G27$F^2,(&F::'*"
	"%R-3&257'\"A9'RM<(2U>(S!@)C)D'8VO'(NK#&>-()2U$WZA#6N,#7F;!VF,\"F.&"
	"#VN.#G>:\"7\"3\"6^1#'B:&HBI!V6&\"FZ.!EE^$766\"VN.$WN?$'Z?%'Z@$W>9\"%5X"
	"\"VF+$'*4%'R>\"7B9#GJ9$'&4\"'*4'(:J*9BZ\"&2&$&.'\"EZ\"'(ZL\"'26\"7.2#W.6"
	"$7F=%X2H%H>I!U9V\"F*$!W>5'8FM-Z;)&5Q^)H*A#EZ\"\"6R.\"W*5&8*B-(BN:IK$"
	"&256&RA9'BI<(2U=(R]@)C)C*#1E%WVA\"%IZ$G66$7RA!VN+#7*4%(&D\"&^0\"6F*"
	"$G28!6B+$GR?$X*D%(&C#725%WF<&X:I%H6H&(>J'(VN$7Z>#F2($F^2#'&2\"FR."
	"$WR?&XBH&8&D#GB<!V^1#7&3#7F9'Y&P%W*7!4US\"6^/&(JK%X*D!6J+%GZ@#W28"
	"*9>Z&X*@#5=Z\"5M^!FB+#'N>(9*S%7R>\"UU_$V>)$FB,$7Z<\"6B-%'R?,W^C9Y[&"
	"'\"=8'BE;(2U=(R]@)3)B*31E*C=H\"GF8#FZ1!FN.$'V>$7.6$W^A#6V0$'.4$&R/"
	"#G.4#7.2\"&^4$WZ?'7V>\"UV!%WB6!TQP!5Q]$767\"FF+!F&\"$&N+\"5A]#7*4$GZ?"
	"%WV?&8&B\"W.5#7J=\"VV/\"F6)$'F:\"GJ:$G6:!V2&%86H+)F]\"V^1((2H\"6V.$GZ@"
	"%7^B\"FR-\"F\"!$7R:$'F;%H:I%W^A#%V\"\"V.&%8\"@\"WF;$'J?\"'&4\"GB;(WN@9*#)"
	"'BI:(\"Q=(B]@)3%B*#1E*S=G+3AJ$H&E$H.E&(JK*I>X\"W\"3\"6^1#7>8(HVN\"6B)"
	"#6J-#G.6#7B<%'F9!DYS\"&>)$6V0!V&$$'R=#GF:!EQ]\"7\"2\"&F-$W^?$G^@'(:H"
	"$GN=%X*F\"G27\"W26!6\"\"#&V/'XZO\"W>8$WZ?$G^A)9>[((VP\"6J+'8>I!FB*'(FK"
	"#6Z3'X.D\"5Y`'8NN#'B;%X6H%82E#GF:&XNN$W^C\"W>8#GV>%8\"B#GB9(H:I592]"
	"(\"M=(B]?)3%B)S1D*C9G+3AJ,#ML&8FJ'HNL$W67#765\"FR.\"F*#\"6J,#WB;$7&5"
	"\"FN,$8*B\"G*5%7V?!VZ/\"'67#V6(!VN+#G.6&G^B\"VV-$H&C$767#6V/#&2(%'B8"
	"$WJ=#7F<!FF+\"&B*!%V!&8\"@$G68\"6:+#'\"1!6J*$GN<!UZ!$'*3\"W68\"&>($'.6"
	"$G><%'Z?!VF)&'ZB!V.$%6F+!EZ\"$'B;%'V>\"EQ_#G>7&86G\"FR-#V^2(82F3(VT"
	"(BY?)#%B)S-D*C9G+#EI+SML,CYN*YV_#7Z@%W^B$7J;\"&*$\"&2'(HZP)).U#G68"
	"$G67&(>H)Y:U\"V2(\"G&3\"'.6\"W*3\"'>8&8>I%8&C#'J;%X*F&H.E$X6C'(BJ$767"
	"#'B:!VF,\"F.&#VN.#G>:\"7\"3\"6^1#'B:&HBI!V6&\"FZ.!EE^$766\"VN.$WN?$'Z?"
	"%'Z@$W>9!U%T\"6>)$'.5#G&4\"G:6(86F\"EZ\"%FR0)9&R#7:9\"%Z\"%'V>&G::0H6N"
	")#%A)S-D*C9F+#AI+SML,CUO,S]Q\"F6(\"7&2\"7*5\"&>)#VR-%'N>$H\"A#7N<\"G.6"
	"$G^B\"':9\"&V/\"U^\"\"G*2\"WJ=)92W$G.8#GF:\"7F;%(:I%HFJ$7F=$W^C#'67#W:8"
	"$W^B\"&^0\"6F*$G28!6B+$GR?$X*D%(&C#725%WF<&X:I%H6H&(>J'(VN$7Z>#F2("
	"$F^2#'&2\"VN-#727)IBW$&V0%&B-&WF<%8*B&H:N#H&A\"6.#\"6\"\"#7.5%7B:/H^U"
	")C-C*35F+#AI+CIL,3UN-#]P-D%S\"&R.\"&^.!UU^\"%%W\"5M^$&V-$GB9#&N/!6F)"
	"\"6.%!FB)\"&2&\"FF*\"&J-\"W27&G^A!D=J\"W&0&(6K%(\"A!FN+\"'\"1#':7#7&4$7R>"
	"#6R/$'.4$&R/#G.4#7.2\"&^4$WZ?'7V>\"UV!%WB6!TQP!5Q]$767\"FF+!F&\"$&N+"
	"\"5=\\#'&3$7R>$':8((BG\"5-Z\"&R-$WF=!F.%\"VZ0#G:9$%R\"%7R?#W67%WV>,X6J"
	"*31F*SAI+CIK,3QN,S]Q-D)S.$1U\"W.5#'28!V^2'X^N((^N#W\"1\"&R.#&N0\"'\"1"
	"\"&N.\"&J,\"VR.\"&2&$'B:(9\"Q#&^1!5Z!!W.5#WV@$'>9\"VZ0$H.A&X>G\"FV0\"6R."
	"#7>8(HVN\"6B)#6J-#G.6#7B<%'F9!DYS\"&>)$6V0!V&$$'R=#GF:!EQ]\"7\"2\"&F-"
	"$W^@$H&B'(JM$W:6$&F+$725\"WJ:)9*V$G66\"&>-#G.3)XVL!VZ0$H\"?#FJ/,Y.U"
	"*S=H+3IK,#QM,S]P-4)R-T1U.D=X!FR,$H&B%(>I((ZP\"FF+\"VR.\"&R/#7B9#7F:"
	"$'.5\"&>)\"W>7$7ZA&XVO&(6I\"%Q\\\"VN.!6^2\"GJ;'8NN$'*4$'V;#6^2\"FF,\"F2%"
	"\"6J,#WB;$7&5\"FN,$8*B\"G*5%7V?!VZ/\"'67#V:)!VN+#G.6&G^B\"VV-$H&C$7:8"
	"#6J,!U9[&(*C!UQ`#6J,\"W\"2%H*C'(6G!E5V#G>:&XJM%7VA$'66#%I\\&&^60:'#"
	"+CIJ,#QM,C]P-4%R-T-U.D=W/$EZ\"VJ.'XFK\"W.7#'*6!FR,&8*A\"6B-%(>H%H.G"
	"%X>H$7\"2$WN;'8JJ!VN-#'24\"&6&!F:(!G:7\"7J;#&^3\"W*4$G26$'26\"62&\"6:)"
	"(HVO)).U#G68$G67&(>H)Y:U\"V2(\"G&3\"'.6#'.4\"'>8&8>I%8&C#'J;%X*F&X:G"
	"#X\">(X^Q%X>I\"7&3\"W\"2\"&Z0#'B9\"W*3!UQ^%'J:$H.C#'B8#G.5!F&#'X:J*HJL"
	"+SML,C]O-$%Q-T-T.D9W/$AY/TM\\#WJ;#6N/$':8\"WJ9!VN.#WR?\"W&6'X>J%'.4"
	"\"%Q]%G>:\"VN,\"VV.$W&3#W67!%9Z$':7\"7&5!W\"3#7J;&(>I%(\"A\"V>*#VV.$WJ="
	"$H\"A#7N<\"G.6$G^B\"':9\"&V/\"U^\"\"G*2\"WJ=)92W$G.8#GF:\"7F;%(:I%XNL$7J>"
	"%(\"D$H&D$X&C#6^1!&&$\"7&2#7R>#7B<\"G:8$'B;\"725&(&D%'R@#&Z2%8&?(GV@"
	",CYO-4!Q-T-T.49V/$AY/TM[04U^\"W\"1#7B:!W65#'25#&R.\"6J,\"VV.#WN:\"%E_"
	"'82E#7>7\"6R/\"'\"/%H2C#&R/#GF:*Y>W#W&4(92U)I2X&XJJ#W\"1!U5Z\"EZ!$&V-"
	"$GB9#&N/!6F)\"6.%!FB)\"&2&\"FF*\"&J-#'27&7Z@!DAK\"W&0&(6K%(\"A!6N+\"'&2"
	"\"7&3!F^0\"G\"1!UE[\"&6(%H:I$(&C$WF:\"WR<\"W&5\"'\"2%H*B\"FN.\"'*0\"E^\")HVO"
	"-$!Q-T)T.45V/$AX/DI[04U^0T]`!VV/%8BG#GJ<#W67\"5^#&GZA%W^A#GB9#7.6"
	"#726\"7&1\"W.4#'>9%H\"B$GR>&8FK&'R?#'24\"G.4&HBH#':6!VN.%X2D'HNK#W\"1"
	"\"&R.#&N0\"'\"1\"&N.\"&J,\"VR.\"&6'$'>9(8^P#&^1!5Z!!W.5#WV@$'>9\"FR-$(\">"
	"#7>7\"&:(\"%=[$6Z1\"'65#WV?%7J>%'>:\"6&$\"&.%\"724!6^2\"F^5!VJ-#FF,&82E"
	"-T)S.45V.TAY/DI[04Q^0T]`1E*#\"&N-#FV/\"VR-!F:(%'N=#FZ/#&F.%HJI!V2)"
	"'8FI$'^>\"FV0!F:+\"W25#7&3!UQ`\"6:(\"G\"0#&R.#VZ1\"F2(#'67&H6H\"VN-\"VR."
	"\"&R/#7B9#7F:$'.5\"&>)\"W>7$7ZA&HNN%X6H\"%]_\"VR/!6^2\"GJ;'8NN#FZ0#X\"="
	"#&F.\"%^$\"G65#GV?#G&7\"G26%H2C$&B,%X*F)(^P#7*4!G\"2%X6H#GZ@$(\"?\"726"
	".41U/$AX/DE[0$U^0T]_1E*\"2%2&\"&N+$F^1!V2%\"W*4\"WF;\"6.&)8VK#W65#G.4"
	"$6Z2!U^!$&^0&H2F#WF;\"W>9&8>I%X6H\"G6:\"W69'8NM'XNJ\"6N/$'B;!VV-&(\"?"
	"\"6B-%(>H%H.G%X>H$7\"2$WN;'8JJ\"&V/#'24\"6B)!F:(!G:7\"7J;\"FV1\"W\"2#VV/"
	"#VJ-#VZ0'8&D!V>)\"&R-$7J;%7R;#&Z.'(2D#&*%!F*$!FJ-)I:Y%(:H$'R?\"G29"
	".T=X/DE[0$Q]0DY`15&\"1U2%2U:'!W*3\"W\"4\"G26!G23!VJ-#W69$W68#&*&$WV<"
	"$G*5%'Z?#7F;\"7&4\"W25\"VZ0$7Z?'(\"C#G:7!W65#'F<\"FV0%'R?#WN;!VF,#WN>"
	"\"W&6'X>J%'.4\"%Q]%G>:\"VN,\"VV.$G&3$':8!5A\\$':7\"7&5!W\"3#7N<&XRN'(JJ"
	"$&B+$'64\"&.%\"W25!W*4!FR0&7^B%':8$G*5\"&N.%H\"C#GR<(XVO\"G67\"&:+\"G*6"
	"/4EZ0$M]0DY_15\"!1U2$2E:'3%F*\"'.3(XZO#FN0#'>8\"G\"2!66&%7B:&8.C\"F.&"
	"\"%=[!V6&\"7&3\"WN=$'>;!F^1$8\"@$&V.#G.3#FV0\"&2%\"W\"2\"WF8#'25#&R.\"6J,"
	"\"VV.#WN:\"%E_'82E#7>7\"6R/\"'\"/%8.B#&R/#GB9*I:V#W&4(92U*)>[()*R%8\"A"
	"!EZ\"#W26!V^2%(2D\"7*3$X\"@$(&B%X*F!UU_\"G64\"6J/%'68\"F>'\"VV-$&:*$82B"
	"0$M\\0DY_1%\"!1U.$2E:'3%B)3UJ,((NL&7V>\"&*&#'N8\"&Z1$7R@'I\"Q\"7.4#7:7"
	"#G^?$H.G*)N[((FJ\"7.3#'J<&XNM%EZ$\"F:'\"6\"$\"F^0%HBH#WN>#G26\"6\"$&GZA"
	"%W^A#GB9#7.6#726\"7&1\"W.4#'>9%H\"B$GR>&8FK&'R?#'24\"G.4&XJJ#':5!V>*"
	"!FN.$W&7#WB:&8\"B#6J-\"F&$#7>6\"FZ/\"5M_((RJ\"VZ1'H6H\"&Z1!V^0\"W*6#'V?"
	"0DY^1%\"!1U.$2E:'3%B)3UN,45V.'Y&O\"UZ\"$W65\"W.1#W.7(8ZN#6R0#'\"2\"6N."
	"\"7\"3#GF;#6N)\"55X\"6^0$'J='HFJ#F.%$W66+)*V\"6V/#W\"2#&Z/!F>(%'N=#FZ/"
	"#&F.%HJI!V2)'8FI$'^>\"FV0!F:+\"W25#7&3!UQ`\"6:(\"G\"0#&R.$&Z2\"%M_!66&"
	"\"V^4%'R?\"F%`\"&*$\"&R-#'\"2#7J;\"G>:#7J:#&J/$7>:$(*B\"WF:$X6D#WN@$7J="
	"1%!`1U.$256&2UB)3EJ+45V.4U^0$&V-#%V!%7*3!VV.((*F\"&&$$7B9#7B9$7:8"
	"'8&B\"F2%\"6\"\"'8NL\"'*6\"'66#GB9\"FN.%X&?\"EA^\"&N+$F^1!V2%\"W*4\"WF;\"6.&"
	")8VK#W65#G.4$6Z2!U^!$&^0&H2F#WF;\"W>9&8>I%X6H\"G6:\"W69'XZP'XNJ!V.'"
	"&H6H#7>7!TMQ\"W>:&XRM$GZ?&(*C!W25&HBI#'R=&(:H\"G\"3$X.C\"&V/!FJ-$W.5"
	"1E*#256&2U>)35F*45V.4U^05F*2\"FF,%X6F#7\"3#766#6F+&7Z?$WJ=%XFH!V2("
	"#&J,#'&2%'R?'7F;!5Y_#G:;\"7*6\"F6(!UE\\$G\"2!W*3\"W\"4\"G26!G23!VJ-#W69"
	"$W68#&*&$WV<$G*5%'Z?#7F;\"7&4\"W25\"VZ0$7Z?'(\"C#G:7!W65#'F<\"6Z0&8*G"
	"&WZ?\"%M]!VJ-#7N?)I\"R\"6B)$G:9#7F<\"W*6%'R>!VB,%7Z>#FV0%'69\"FB%!UI]"
	"2%2%2U:(3EF+4%R-4U^05F&26&.5#7F9&(\"C#G27!VR-$GN;%8*B$W:7!V\"$#&V0"
	"'8FJ!EY_&(*D$W66\"FJ-$'VA#GB9#G*2&XJN(I.W\"'.3(XZO#FN0#'>8\"G\"2!66&"
	"%7B:&8.C\"F.&\"%=[!V6&\"7&3\"WN=$'>;!F^1$8\"@$&V.#G.3#FV0!EY^\"FJ+$'^="
	"\"G25\"&V0\"&Z.$H.D$X>G%7><\"W.5)Y2T!V2##7\"0!VF-#G25!F.%#V>)\"%=\\#G:6"
	"2U>(35J*3UR-4E^056\"25V246F:7#(&C#W^>#7.1#6&'()\"R%XBI#'68#GV>(H^N"
	"#F^0!V:&%8&A$&*(!F2$%H.C!6F,'8ZP#W>9!V&$((NL&7V>\"&*&#'N8\"&Z1$7R@"
	"'I\"Q\"7.4#7:7#G^?$H.G*)N[((FJ\"7.3#'J<&XNM%EZ$\"F:'\"6\"$#W*3&(BK$X\"C"
	"\"&V0!FN-$X*B))*U'(BK$&Z3#&J+&6Z2$VZ2$H*B$7F>&8\"C\"6J,!F.&!G&1!FJ-"
	"35B*4%R,4EZ/5&&25V.466:776B:#':8!V\"!\"4MQ)(VK%H6H\"G>8!VZ2$H&C$&R/"
	"\"%-W#VB)$WR;#'\"2(8JK\"F^4#GR=\"W>:\"6N,!V\"\"'Y&O\"UZ\"$W65\"W.1#W.7(8ZN"
	"#6R0#'\"2\"6N.\"7\"3#GF;#6N)\"55X\"6^0$'J='HFJ#F.%$W66+)*V$WZA&(FK'H:J"
	"\"7&1#W66\"&&%#'>8\"&Z0\"FV/\"&F+\"F>)$WR=%H&B#G:8$6>'!EA[#WV=#'*6!G.5"
	"3UR,4EZ.56\"25V.46F667&B97VN<\"&>&$66)\"62(#&6%#F.%!UE[!5U`\"'\"0!6\"$"
	"#7\"1&(*D#'\"3$'N=#'F;$'R?&(FL$7R>\"G*3!V>)$&V-#%V!%7*3!VV.((*F\"&&$"
	"$7B9#7B9$7:8'8&B\"F2%\"6\"\"'8NL\"'*6\"'66#GB9\"FN.%X&?\"EA^(H:G$WR<\"&6)"
	"!G&2\"FN-!5Q_$7N=#WN<\"V:*\"G\"3$X&C#'*3$7:7#'B;!DIN#'B8!VR1\"G\"4)Y>V"
	"45V.5&\"15V.466667&B97FJ<86V=#&>*+I>U\"%1Z'XRK$GF=&8.F\"WJ:\"WB9!&N."
	"$GV@#'F<\"'*6\"G67(8^P%WZ@$6^0!EU_\"VN,$'68\"FF,%X6F#7\"3#766#6F+&7Z?"
	"$WJ=%XFH!V2(#&J,#'&2%'R?'7F;!5Y_#G:;\"7*6\"F6(!UE\\$G\"2,J/$!VZ.\"&R."
	"%H.D!V>,#'*4#WR?&H:H\"FZ/#'\"3#GF:\"6Z2#'26%(*D#6F&!FR/\"G67)I.U$W>8"
	"5&\"05F*36&667&B87FJ;8&V=8V^@\"G.3%F^1!TAJ+YJ]#6R/\"W&4#WN;\"&Z0!&6)"
	"\"WB:&XFL\"'26*I2V&W:9\"%Z\"$6R,!VV0!F.''8JG#7F9&(\"C#G27!VR-$GN;%8*B"
	"$W:7!V\"$#&V0'8FJ!EY_&(*D$W66\"FJ-$'VA#GB9#G*2&XJN(I.W#W.3!F6&!F*%"
	"&'V>\"&2'$W^?'8VM&G^?!U9Y\"F:*#7>;!62$%'J>$'R=$F&%\"FR.\"GJ9#GB8#WF:"
	"5F*36&256V>876J;8&V=8V^@97*B$'25\"$AN#FZ0'XJJ%WR?&(JK#7>8\"&V.\"G25"
	"\"W.7#'J;\"7&0%6V/#5V\"\"V^1%H*E$W*6$G27(HFM#(&C#W^>#7.1#6&'()\"R%XBI"
	"#'68#GV>(H^N#F^0!V:&%8&A$&*(!F2$%H.C!6F,'8ZP#W>9!V&$#VR0\"&F*\"7*2"
	"%(.B\"VF-'H2G!V*$!UE]%'*3#&R-\"G27%'ZA)Y:X#&^-\"T]V&8&C(9*T)YJY!V^/"
	"6&256V:876F;8&R<8V^@97&B:'.E$'J<!V*$&(:J(I\"Q&(2E$W^@!V*&&8.D\"6B*"
	"#GR=\"WN=#'\"3#W.4$W>8)(VQ%GR=!UQ^'H6E$GJ>#':8!V\"!\"4MQ)(VK%H6H\"G>8"
	"!VZ2$H&C$&R/\"%-W#VB)$WR;#'\"2(8JK\"F^4#GR=\"W>:\"6N,!V\"\"#G66\"6>*!V>)"
	"\"6Z/!VN-$'27!V6(\"763\"VF,%H6E&HFJ)I>U%'26!E1X(8FH(HNO$'\"3\"VN,!EA]"
	"6F:876F:7VN=8VZ?97\"B9W.E:G:G%(*A\"VR/'8BJ%X6E#G&3$GB9#V^1$7Z>\"F:)"
	"$'.5\"6Z1!FN.\"&R.&X:G#GJ;!EI\\%7J:#GV<%82G\"&>&$66)\"62(#&6%#F.%!UE["
	"!5U`\"'\"0!6\"$#7\"1&(*D#'\"3$'N=#'F;$'R?&(FL$7R>\"G*3!V>)\"&J-'(&C\"&>+"
	"#7F9\"G.6&8*E!G\"1\"6R/%G>;%8FG#VR1\"&B-!6R,#6Z/%GJ:!V6($GN<!F>*!6>*"
	"76B:7VN<8FV?97\"B9W.D:7:G;'BI#7F;#&B-\"VN-$7J;#G69#FZ1&H\"C\"6>(#'\"2"
	"\"&F+\"G*4\"'27\"GB;\"W>:#7\"4!V\"#$7Z=$WV@$7::#&>*+I>U\"%1Z'XRK$GF=&8.F"
	"\"WJ:\"WB9!&N.$GV@#'F<\"'*6\"G67(8^P%WZ@$6^0!EU_\"VN,$'68\"'>9%WV?\"6>*"
	"\"V^2$7R?!VR0$GR?!6F,#GR=&XVM#7:8$'F:%W^?#V>+\"FN.\"G27$768$GR<\"&:*"
	"7FN<86V>9'\"B9W.D:76F:WBI;GJK<7VN<X\"P=X.S>86V>X>X?HJ[@8R^@X^`AI'#"
	"B)7%BY?(CIK*D)S-DI[/EJ'2F*/5FJ;7G:G9GZO<\"G.3%F^1!TAJ+YJ]#6R/\"W&4"
	"#WN;\"&Z0!&6)\"WB:&XFL\"'26*I2V&W:9\"%Z\"$6R,!VV0!F.''8JG%X*F%H&D#7:9"
	"#7V>\"6Z3#WN=&(.A!F&$#W>8#727#G::\"6B)#V:(&'N<&XJK%X6H%WZ?#'\"2\"6R/"
	"86V>9'\"A9G.C:76F;'>H;GJK<7VM<W^P=8*R>(6U>X>X?HF[@(V]@X^`A9'#AY3%"
	"BY?'C9G*D)S-DI[0E*'2EZ/5F:;7G*C9GZO<H:W?$'25\"$AN#FZ0'XJJ%WR?&(JK"
	"#7>8\"&V.\"G25\"W.7#'J;\"7&0%6V/#5V\"\"V^1%H*E$W*6$G27(HFM(XZR\"&N/&86H"
	"\"VV2\"G&5#'*6\"&F*!&\"#\"W>7!F^1'(6H#&R.%G\"2#F2'\"W&2%'V>\"%!U#FZ/\"'\"1"
	"9'\"@9G*C:76E:W>H;GFK<'RN<W^P=H&R>(2U>X>X?HF[@(R]@XZ`A9#\"AY3%BI;'"
	"C)G)D)O-DI[/E*#2EZ/4FJ;7G*C9GZO;H:W>I+#A$'J<!V*$&(:J(I\"Q&(2E$W^@"
	"!V*&&8.D\"6B*#GR=\"WN=#7\"3#W.4%'>8)8VQ%WR=!UQ^'H6E$GJ>$H&A\"&Z0$X2E"
	"!F6)!FN,#'F;\"G*4#'>9$8*D#GJ?$X&C\"6:&\"F.%$&^1$7:8'7N?#FR0&(.C#GR?"
	"9G*C:'6E:W>H;GJJ<'RM<WZP=8&R>(.T>X:W?8FZ@(N]@HZ_A)#!AY/$BI7'C)G)"
	"CYO,D9[/E*#1EJ+4FJ;7G*C9GJK;H:W>I*_AIK+D%(*A\"VR/'8BJ%X6E#G&3$GB9"
	"#V^1$7Z>\"V:)$7.5\"FZ1!VN.\"&R.'(:G#WJ;!UM]%GJ:#WV<%82G\"W>:\"':4\"7J:"
	"!V&%#&R-\"'B9\"G:6((VM$768\"W.6%H*D!E^\"\"V2)$'B;'HRK#6:(&X2G%X\"B)XVO"
	":'2E:W:G;7JJ;WRM<GZO=8&R=X.U>H:W?(FY?XN]@HZ_A9'!AY/$BI7&C)C)CIO,"
	"D9W.DZ#0EJ/3F:76G*?9GJK<H*W>HZ_@IK+BJ+7F#7F;#&B-\"VN-$7J;#W69#VZ1"
	"&X\"C\"F>(#7\"2\"6J,#'.5\"W:9#GJ>$'F=$G.7#&.&%8\"?%7ZA$G::\"G*6\"FB+#7:8"
	"!V&%!F6&#GN>&8BJ#FR/\"6:(\"G66(8ZR!FF*%'R=&H:G$&^2'7Z?*(NN.9>Y,X6I"
	":G:G;7FJ<'RM<GZO=8\"Q=X.T>H6W?(FZ?XN\\@8V^A)#!AY/#B97&C)?)CIO+D9W."
	"E)_1EJ+3F:76FZC9GJK;H*S=HZ_@IK+CJ+3EJ[?HK;KKL+SMLK[OM<'RN,3TNL;W"
	"O<GZP,S]PL[_Q=$\"Q]0$RM<&S-D)SMP,T=X/U.$0UN04V>86W.@9WNP;X>X>Y/$@"
	"YO,CZ/4F[/@H[OLK\\/XM\\_`P]P(R^04U^P<X_@HZ_`T\\``\\_````````````````"
	";'FI;WNL<7VN=8\"R=H.T>H6V?(BY?XN\\@8V_A(_!AY/$B97&BY?(CIK+D9S.DY_0"
	"EJ+3F:35FZ?8G:G;H*S=HZ_?I;+CJ+/EJK?GK;GJL+SLLK[OM<'QM\\3UNL7WO,CY"
	"O\\O\\PLW_Q-$!QM0$R=<'S-D)S]P+T=X.U.$1UN,3V>46W.@9WNL;X.T=X^`@YO,B"
	"Z/8EZ_<H[?LJ\\/TM\\O\\P]@(R^04U^`<W_@HZ_`T\\`P\\`````````````````````"
	";WNL<GZN=(\"Q=H.S>86V?(>X?HJ[@8R^@Y#!AI+#B97&BY?)CIG*D)S-DY[/E:'2"
	"F*35FZ?7GJG:H*S<HJ[@I;'BJ+/DJK;GK+GIK[OMLK[NM,#RML/SNL;WO,CYO\\O\\"
	"P<W^Q-$!Q]0#R=4&S-D)SML,T=X-T^$0UN,3V>45V^D8W>L:X>X=X^`?Y?,BZ/0E"
	"Z_@G[?HJ\\/PM\\O`O]@$R]`0T^P<W_0HY_`P\\`P\\_````````````````````````"
	"<7VN='^P=H*S>86V>X>X?HJ[@(R]@X^`A9+\"B)3%BI?(CIG*D)S-DI[/E:'2F*35"
	"FJ;7G:G:H*O<HJ[?I;'BI[3DJK;FK+GIK[OKL;WOM,#QML/SN<7VO,CYOLO\\P,W^"
	"Q,`!QM,#R-4&R]@(SML+T-X.T]`0UN,2V.45V^@8W>H:X.T=XN\\@Y?(BY_4EZO@G"
	"[?DJ[_PL\\O\\N]@(Q]`0T^@8W_0DY_`P[`@X^````````````````````````````"
	"<X\"P=8&S>(2U>X>X?HFZ@(R]@X^`A9'\"B)3%BI?'C9G*CYS,DI[0E*'2F*34FJ77"
	"G*G:GZO<HJW?I+#AI[/CJ;;FK+CIKKOLL;WOM,#PML/SN<7VN\\?XOLK[P<S^P\\`!"
	"QM,#R-4%R]@(SMH*T-T-T]`0U>(2V.04VN<8W>H:X.P=XN`?Y?$BZ/0EZO<F[/DI"
	"[_PL\\?XO]0$R]`,T^@8V_0DY_PL[`@X^````````````````````````````````"
	"=8*R>(2U>H>X?8F[@(R]@X^`A9'\"B)3%BI;'C)C*CYO,DI[/E:#2EZ/4F:77G*G9"
	"GZO<H:[>I+#AIK+CJ;7FJ[?HK[KLL;WNM+_PML+SN<3UN\\?XOLGZP,S^P\\_`Q=(\""
	"R-4%RM<(SMH*T-T,TM`/U>(2V.45VN<7W.H:W^P<X>\\?Y?(AY_0DZ?8G[/DI[OPL"
	"\\?XN\\`$P]P0S^@8V_0DY_`P\\`@T]````````````````````````````````````"
	"";
