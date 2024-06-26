﻿#include <map>
#include <tuple>


// no endianness required
//win1254 hex --  unicode code point  -- utf8 code unit - byte size 

//std::map<uint8_t, std::tuple<char16_t, char32_t, uint8_t>> win1254map
//{
//	{0x80, {0x20AC, 0xE282AC, 3} },
//	{0x81, {0xFFFF, 0xEFBFBF, 3} }
//};


std::map<uint8_t, std::tuple<char16_t, char32_t, uint8_t>> win1254ToUtf8
{
	{0x80, {0x20AC, 0xE282AC, 3} },			//  €	//  Euro Sign
	{0x81, {0xFFFF, 0xEFBFBF, 3} },			//		//  Undefined Character
	{0x82, {0x201A, 0xE2809A, 3} },			//  ' 	//	SINGLE LOW-9 QUOTATION MARK
	{0x83, {0x0192, 0xC692, 2}	 },			//  ƒ 	//	LATIN SMALL LETTER F WITH HOOK
	{0x84, {0x201E, 0xE2809E, 3} },			//  „ 	//	DOUBLE LOW-9 QUOTATION MARK
	{0x85, {0x2026, 0xE280A6, 3} },			//  … 	//	HORIZONTAL ELLIPSIS
	{0x86, {0x2020, 0xE280A0, 3} },			//  †	//	DAGGER
	{0x87, {0x2021, 0xE280A1, 3} },			// 	‡	//	DOUBLE DAGGER
	{0x88, {0x02C6, 0xCB86, 2}	 },			// 	ˆ	//	MODIFIER LETTER CIRCUMFLEX ACCENT
	{0x89, {0x2030, 0xE280B0, 3} },			// 	‰	//	PER MILLE SIGN
	{0x8A, {0x0160, 0xC5A0, 2} },			// 	Š	//	LATIN CAPITAL LETTER S WITH CARON
	{0x8B, {0x2039, 0xE280B9, 3} },			// 	‹	//	Single Left-Pointing Angle Quotation Mark
	{0x8C, {0x0152, 0xC592, 2} },			// 	Œ	//	Latin Capital Ligature Oe
	{0x8D, {0xFFFF, 0xEFBFBF, 3} },			// 		//	Undefined Character
	{0x8E, {0xFFFF, 0xEFBFBF, 3} },			// 		//	Undefined Character
	{0x8F, {0xFFFF, 0xEFBFBF, 3} },			// 		//	Undefined Character
	{0x90, {0xFFFF, 0xEFBFBF, 3} },			// 		//	Undefined Character
	{0x91, {0x2018, 0xE28098, 3} },			// 	‘	//	Left Single Quotation Mark
	{0x92, {0x2019, 0xE28099, 3} },			// 	’	//	Right Single Quotation Mark
	{0x93, {0x201C, 0xE2809C, 3} },			// 	“	//	Left Double Quotation Mark
	{0x94, {0x201D, 0xE2809D, 3} },			// 	”	//	Right Double Quotation Mark
	{0x95, {0x2022, 0xE280A2, 3} },			// 	•	//	Bullet
	{0x96, {0x2013, 0xE28093, 3} },			// 	–	//	En Dash
	{0x97, {0x2014, 0xE28094, 3} },			// 	—	//	Em Dash
	{0x98, {0x02DC, 0xCB9C, 2} },			// 	˜	//	Small Tilde
	{0x99, {0x2122, 0xE284A2, 3} },			// 	™	//	Trade Mark Sign
	{0x9A, {0x0161, 0xC5A1, 2} },			// 	š	//	Latin Small Letter S with Caron
	{0x9B, {0x203A, 0xE280BA, 3} },			// 	›	//	Single Right-Pointing Angle Quotation Mark
	{0x9C, {0x0153, 0xC593, 2} },			// 	œ	//	Latin Small Ligature Oe
	{0x9D, {0xFFFF, 0xEFBFBF, 3} },			// 		//	Undefined Character
	{0x9E, {0xFFFF, 0xEFBFBF, 3} },			// 		//	Undefined Character
	{0x9F, {0x0178, 0xC5B8, 2} },			// 	Ÿ	//	Latin Capital Letter Y with Diaeresis
	{0xA0, {0x00A0, 0xC2A0, 2} },			// 	 	//	No-Break Space (NBSP)
	{0xA1, {0x00A1, 0xC2A1, 2} },			// 	¡	//	Inverted Exclamation Mark
	{0xA2, {0x00A2, 0xC2A2, 2} },			// 	¢	//	Cent Sign
	{0xA3, {0x00A3, 0xC2A3, 2} },			// 	£	//	Pound Sign
	{0xA4, {0x00A4, 0xC2A4, 2} },			// 	¤	//	Currency Sign
	{0xA5, {0x00A5, 0xC2A5, 2} },			// 	¥	//	Yen Sign
	{0xA6, {0x00A6, 0xC2A6, 2} },			// 	¦	//	Broken Bar
	{0xA7, {0x00A7, 0xC2A7, 2} },			// 	§	//	Section Sign
	{0xA8, {0x00A8, 0xC2A8, 2} },			// 	¨	//	Diaeresis
	{0xA9, {0x00A9, 0xC2A9, 2} },			// 	©	//	Copyright Sign
	{0xAA, {0x00AA, 0xC2AA, 2} },			// 	ª	//	Feminine Ordinal Indicator
	{0xAB, {0x00AB, 0xC2AB, 2} },			// 	«	//	Left-pointing Double Angle Quotation Mark
	{0xAC, {0x00AC, 0xC2AC, 2} },			// 	¬	//	Not Sign
	{0xAD, {0x00AD, 0xC2AD, 2} },			// 		//	Soft Hyphen
	{0xAE, {0x00AE, 0xC2AE, 2} },			// 	®	//	Registered Sign
	{0xAF, {0x00AF, 0xC2AF, 2} },			// 	¯	//	Macron
	{0xB0, {0x00B0, 0xC2B0, 2} },			// 	Ÿ	//	Degree Sign
	{0xB1, {0x00B1, 0xC2B1, 2} },			// 	±	//	Plus-minus Sign
	{0xB2, {0x00B2, 0xC2B2, 2} },			// 	²	//	Superscript Two
	{0xB3, {0x00B3, 0xC2B3, 2} },			// 	³	//	Superscript Three
	{0xB4, {0x00B4, 0xC2B4, 2} },			// 	´	//	Acute Accent
	{0xB5, {0x00B5, 0xC2B5, 2} },			// 	µ	//	Micro Sign
	{0xB6, {0x00B6, 0xC2B6, 2} },			// 	¶	//	Pilcrow Sign
	{0xB7, {0x00B7, 0xC2B7, 2} },			// 	·	//	Middle Dot
	{0xB8, {0x00B8, 0xC2B8, 2} },			// 	¸	//	Cedilla
	{0xB9, {0x00B9, 0xC2B9, 2} },			// 	¹	//	Superscript One
	{0xBA, {0x00BA, 0xC2BA, 2} },			// 	º	//	Masculine Ordinal Indicator
	{0xBB, {0x00BB, 0xC2BB, 2} },			// 	»	//	Right-pointing Double Angle Quotation Mark
	{0xBC, {0x00BC, 0xC2BC, 2} },			// 	¼	//	Vulgar Fraction One Quarter
	{0xBD, {0x00BD, 0xC2BD, 2} },			// 	½	//	Vulgar Fraction One Half
	{0xBE, {0x00BE, 0xC2BE, 2} },			// 	¾	//	Vulgar Fraction Three Quarters
	{0xBF, {0x00BF, 0xC2BF, 2} },			// 	¿	//	Inverted Question Mark
	{0xC0, {0x00C0, 0xC380, 2} },			// 	À	//	Latin Capital Letter A With Grave
	{0xC1, {0x00C1, 0xC381, 2} },			// 	Á	//	Latin Capital Letter A With Acute
	{0xC2, {0x00C2, 0xC382, 2} },			// 	Â	//	Latin Capital Letter A With Circumflex
	{0xC3, {0x00C3, 0xC383, 2} },			// 	Ã	//	Latin Capital Letter A With Tilde
	{0xC4, {0x00C4, 0xC384, 2} },			// 	Ä	//	Latin Capital Letter A With Diaeresis
	{0xC5, {0x00C5, 0xC385, 2} },			// 	Å	//	Latin Capital Letter A With Ring Above
	{0xC6, {0x00C6, 0xC386, 2} },			// 	Æ	//	Latin Capital Letter Ae
	{0xC7, {0x00C7, 0xC387, 2} },			// 	Ç	//	Latin Capital Letter C With Cedilla
	{0xC8, {0x00C8, 0xC388, 2} },			// 	È	//	Latin Capital Letter E With Grave
	{0xC9, {0x00C9, 0xC389, 2} },			// 	É	//	Latin Capital Letter E With Acute
	{0xCA, {0x00CA, 0xC38A, 2} },			// 	Ê	//	Latin Capital Letter E With Circumflex
	{0xCB, {0x00CB, 0xC38B, 2} },			// 	Ë	//	Latin Capital Letter E With Diaeresis
	{0xCC, {0x00CC, 0xC38C, 2} },			// 	Ì	//	Latin Capital Letter I With Grave
	{0xCD, {0x00CD, 0xC38D, 2} },			// 	Í	//	Latin Capital Letter I With Acute
	{0xCE, {0x00CE, 0xC38E, 2} },			// 	Î	//	Latin Capital Letter I With Circumflex
	{0xCF, {0x00CF, 0xC38F, 2} },			// 	Ï	//	Latin Capital Letter I With Diaeresis
	{0xD0, {0x011E, 0xC49E, 2} },			// 	Ğ	//	Latin Capital Letter G with Breve
	{0xD1, {0x00D1, 0xC391, 2} },			// 	Ñ	//	Latin Capital Letter N With Tilde
	{0xD2, {0x00D2, 0xC392, 2} },			// 	Ò	//	Latin Capital Letter O With Grave
	{0xD3, {0x00D3, 0xC393, 2} },			// 	Ó	//	Latin Capital Letter O With Acute
	{0xD4, {0x00D4, 0xC394, 2} },			// 	Ô	//	Latin Capital Letter O With Circumflex
	{0xD5, {0x00D5, 0xC395, 2} },			// 	Õ	//	Latin Capital Letter O With Tilde
	{0xD6, {0x00D6, 0xC396, 2} },			// 	Ö	//	Latin Capital Letter O With Diaeresis
	{0xD7, {0x00D7, 0xC397, 2} },			// 	×	//	Multiplication Sign
	{0xD8, {0x00D8, 0xC398, 2} },			// 	Ø	//	Latin Capital Letter O With Stroke
	{0xD9, {0x00D9, 0xC399, 2} },			// 	Ù	//	Latin Capital Letter U With Grave
	{0xDA, {0x00DA, 0xC39A, 2} },			// 	Ú	//	Latin Capital Letter U With Acute
	{0xDB, {0x00DB, 0xC39B, 2} },			// 	Û	//	Latin Capital Letter U With Circumflex
	{0xDC, {0x00DC, 0xC39C, 2} },			// 	Ü	//	Latin Capital Letter U With Diaeresis
	{0xDD, {0x0130, 0xC4B0, 2} },			// 	İ	//	Latin Capital Letter I with Dot Above
	{0xDE, {0x015E, 0xC59E, 2} },			// 	Ş	//	Latin Capital Letter S with Cedilla
	{0xDF, {0x00DF, 0xC39F, 2} },			// 	ß	//	Latin Small Letter Sharp S
	{0xE0, {0x00E0, 0xC3A0, 2} },			// 	à	//	Latin Small Letter A With Grave
	{0xE1, {0x00E1, 0xC3A1, 2} },			// 	á	//	Latin Small Letter A With Acute
	{0xE2, {0x00E2, 0xC3A2, 2} },			// 	â	//	Latin Small Letter A With Circumflex
	{0xE3, {0x00E3, 0xC3A3, 2} },			// 	ã	//	Latin Small Letter A With Tilde
	{0xE4, {0x00E4, 0xC3A4, 2} },			// 	ä	//	Latin Small Letter A With Diaeresis
	{0xE5, {0x00E5, 0xC3A5, 2} },			// 	å	//	Latin Small Letter A With Ring Above
	{0xE6, {0x00E6, 0xC3A6, 2} },			// 	æ	//	Latin Small Letter Ae
	{0xE7, {0x00E7, 0xC3A7, 2} },			// 	ç	//	Latin Small Letter C With Cedilla
	{0xE8, {0x00E8, 0xC3A8, 2} },			// 	è	//	Latin Small Letter E With Grave
	{0xE9, {0x00E9, 0xC3A9, 2} },			// 	é	//	Latin Small Letter E With Acute
	{0xEA, {0x00EA, 0xC3AA, 2} },			// 	ê	//	Latin Small Letter E With Circumflex
	{0xEB, {0x00EB, 0xC3AB, 2} },			// 	ë	//	Latin Small Letter E With Diaeresis
	{0xEC, {0x00EC, 0xC3AC, 2} },			// 	ì	//	Latin Small Letter I With Grave
	{0xED, {0x00ED, 0xC3AD, 2} },			// 	í	//	Latin Small Letter I With Acute
	{0xEE, {0x00EE, 0xC3AE, 2} },			// 	î	//	Latin Small Letter I With Circumflex
	{0xEF, {0x00EF, 0xC3AF, 2} },			// 	ï	//	Latin Small Letter I With Diaeresis
	{0xF0, {0x011F, 0xC49F, 2} },			// 	ğ	//	Latin Small Letter G with Breve
	{0xF1, {0x00F1, 0xC3B1, 2} },			// 	ñ	//	Latin Small Letter N With Tilde
	{0xF2, {0x00F2, 0xC3B2, 2} },			// 	ò	//	Latin Small Letter O With Grave
	{0xF3, {0x00F3, 0xC3B3, 2} },			// 	ó	//	Latin Small Letter O With Acute
	{0xF4, {0x00F4, 0xC3B4, 2} },			// 	ô	//	Latin Small Letter O With Circumflex
	{0xF5, {0x00F5, 0xC3B5, 2} },			// 	õ	//	Latin Small Letter O With Tilde
	{0xF6, {0x00F6, 0xC3B6, 2} },			// 	ö	//	Latin Small Letter O With Diaeresis
	{0xF7, {0x00F7, 0xC3B7, 2} },			// 	÷	//	Division Sign
	{0xF8, {0x00F8, 0xC3B8, 2} },			// 	ø	//	Latin Small Letter O With Stroke
	{0xF9, {0x00F9, 0xC3B9, 2} },			// 	ù	//	Latin Small Letter U With Grave
	{0xFA, {0x00FA, 0xC3BA, 2} },			// 	ú	//	Latin Small Letter U With Acute
	{0xFB, {0x00FB, 0xC3BB, 2} },			// 	û	//	Latin Small Letter U With Circumflex
	{0xFC, {0x00FC, 0xC3BC, 2} },			// 	ü	//	Latin Small Letter U With Diaeresis
	{0xFD, {0x0131, 0XC4B1, 2} },			// 	ı	//	Latin Small Letter Dotless I
	{0xFE, {0x015F, 0xC59F, 2} },			// 	ş	//	Latin Small Letter S with Cedilla
	{0xFF, {0x00FF, 0xC3BF, 2} }			// 	ÿ	//	Latin Small Letter Y With Diaeresis
	
};



std::map<char32_t, uint8_t> utf8ToWin1254
{
	{0xE282AC	,	0x80	},
	{0xEFBFBF	,	0x81	},
	{0xE2809A	,	0x82	},
	{0xC692		,	0x83	},
	{0xE2809E	,	0x84	},
	{0xE280A6	,	0x85	},
	{0xE280A0	,	0x86	},
	{0xE280A1	,	0x87	},
	{0xCB86		,	0x88	},
	{0xE280B0	,	0x89	},
	{0xC5A0		,	0x8A	},
	{0xE280B9	,	0x8B	},
	{0xC592		,	0x8C	},
//	{0xEFBFBF	,	0x8D	},
//	{0xEFBFBF	,	0x8E	},
//	{0xEFBFBF	,	0x8F	},
//	{0xEFBFBF	,	0x90	},
	{0xE28098	,	0x91	},
	{0xE28099	,	0x92	},
	{0xE2809C	,	0x93	},
	{0xE2809D	,	0x94	},
	{0xE280A2	,	0x95	},
	{0xE28093	,	0x96	},
	{0xE28094	,	0x97	},
	{0xCB9C		,	0x98	},
	{0xE284A2	,	0x99	},
	{0xC5A1		,	0x9A	},
	{0xE280BA	,	0x9B	},
	{0xC593		,	0x9C	},
//	{0xEFBFBF	,	0x9D	},
//	{0xEFBFBF	,	0x9E	},
	{0xC5B8		,	0x9F	},
	{0xC2A0		,	0xA0	},
	{0xC2A1		,	0xA1	},
	{0xC2A2		,	0xA2	},
	{0xC2A3		,	0xA3	},
	{0xC2A4		,	0xA4	},
	{0xC2A5		,	0xA5	},
	{0xC2A6		,	0xA6	},
	{0xC2A7		,	0xA7	},
	{0xC2A8		,	0xA8	},
	{0xC2A9		,	0xA9	},
	{0xC2AA		,	0xAA	},
	{0xC2AB		,	0xAB	},
	{0xC2AC		,	0xAC	},
	{0xC2AD		,	0xAD	},
	{0xC2AE		,	0xAE	},
	{0xC2AF		,	0xAF	},
	{0xC2B0		,	0xB0	},
	{0xC2B1		,	0xB1	},
	{0xC2B2		,	0xB2	},
	{0xC2B3		,	0xB3	},
	{0xC2B4		,	0xB4	},
	{0xC2B5		,	0xB5	},
	{0xC2B6		,	0xB6	},
	{0xC2B7		,	0xB7	},
	{0xC2B8		,	0xB8	},
	{0xC2B9		,	0xB9	},
	{0xC2BA		,	0xBA	},
	{0xC2BB		,	0xBB	},
	{0xC2BC		,	0xBC	},
	{0xC2BD		,	0xBD	},
	{0xC2BE		,	0xBE	},
	{0xC2BF		,	0xBF	},
	{0xC380		,	0xC0	},
	{0xC381		,	0xC1	},
	{0xC382		,	0xC2	},
	{0xC383		,	0xC3	},
	{0xC384		,	0xC4	},
	{0xC385		,	0xC5	},
	{0xC386		,	0xC6	},
	{0xC387		,	0xC7	},
	{0xC388		,	0xC8	},
	{0xC389		,	0xC9	},
	{0xC38A		,	0xCA	},
	{0xC38B		,	0xCB	},
	{0xC38C		,	0xCC	},
	{0xC38D		,	0xCD	},
	{0xC38E		,	0xCE	},
	{0xC38F		,	0xCF	},
	{0xC49E		,	0xD0	},
	{0xC391		,	0xD1	},
	{0xC392		,	0xD2	},
	{0xC393		,	0xD3	},
	{0xC394		,	0xD4	},
	{0xC395		,	0xD5	},
	{0xC396		,	0xD6	},
	{0xC397		,	0xD7	},
	{0xC398		,	0xD8	},
	{0xC399		,	0xD9	},
	{0xC39A		,	0xDA	},
	{0xC39B		,	0xDB	},
	{0xC39C		,	0xDC	},
	{0xC4B0		,	0xDD	},
	{0xC59E		,	0xDE	},
	{0xC39F		,	0xDF	},
	{0xC3A0		,	0xE0	},
	{0xC3A1		,	0xE1	},
	{0xC3A2		,	0xE2	},
	{0xC3A3		,	0xE3	},
	{0xC3A4		,	0xE4	},
	{0xC3A5		,	0xE5	},
	{0xC3A6		,	0xE6	},
	{0xC3A7		,	0xE7	},
	{0xC3A8		,	0xE8	},
	{0xC3A9		,	0xE9	},
	{0xC3AA		,	0xEA	},
	{0xC3AB		,	0xEB	},
	{0xC3AC		,	0xEC	},
	{0xC3AD		,	0xED	},
	{0xC3AE		,	0xEE	},
	{0xC3AF		,	0xEF	},
	{0xC49F		,	0xF0	},
	{0xC3B1		,	0xF1	},
	{0xC3B2		,	0xF2	},
	{0xC3B3		,	0xF3	},
	{0xC3B4		,	0xF4	},
	{0xC3B5		,	0xF5	},
	{0xC3B6		,	0xF6	},
	{0xC3B7		,	0xF7	},
	{0xC3B8		,	0xF8	},
	{0xC3B9		,	0xF9	},
	{0xC3BA		,	0xFA	},
	{0xC3BB		,	0xFB	},
	{0xC3BC		,	0xFC	},
	{0xC4B1		,	0xFD	},
	{0xC59F		,	0xFE	},
	{0xC3BF		,	0xFF	}
};


	/*
	
	{0x80, 0x20AC },
	{0x81, 0xFFFF },
	{0x82, 0x201A },
	{0x83, 0x0192 },
	{0x84, 0x201E },
	{0x85, 0x2026 },
	{0x86, 0x2020 },
	{0x87, 0x2021 },
	{0x88, 0x02C6 },
	{0x89, 0x2030 },
	{0x8A, 0x0160 },
	{0x8B, 0x2039 },
	{0x8C, 0x0152 },
	{0x8D, 0xFFFF },
	{0x8E, 0xFFFF },
	{0x8F, 0xFFFF },
	{0x90, 0xFFFF },
	{0x91, 0x2018 },
	{0x92, 0x2019 },
	{0x93, 0x201C },
	{0x94, 0x201D },
	{0x95, 0x2022 },
	{0x96, 0x2013 },
	{0x97, 0x2014 },
	{0x98, 0x02DC },
	{0x99, 0x2122 },
	{0x9A, 0x0161 },
	{0x9B, 0x203A },
	{0x9C, 0x0153 },
	{0x9D, 0xFFFF },
	{0x9E, 0xFFFF },
	{0x9F, 0x0178 },
	{0xA0, 0x00A0 },
	{0xA1, 0x00A1 },
	{0xA2, 0x00A2 },
	{0xA3, 0x00A3 },
	{0xA4, 0x00A4 },
	{0xA5, 0x00A5 },
	{0xA6, 0x00A6 },
	{0xA7, 0x00A7 },
	{0xA8, 0x00A8 },
	{0xA9, 0x00A9 },
	{0xAA, 0x00AA },
	{0xAB, 0x00AB },
	{0xAC, 0x00AC },
	{0xAD, 0x00AD },
	{0xAE, 0x00AE },
	{0xAF, 0x00AF },
	{0xB0, 0x00B0 },
	{0xB1, 0x00B1 },
	{0xB2, 0x00B2 },
	{0xB3, 0x00B3 },
	{0xB4, 0x00B4 },
	{0xB5, 0x00B5 },
	{0xB6, 0x00B6 },
	{0xB7, 0x00B7 },
	{0xB8, 0x00B8 },
	{0xB9, 0x00B9 },
	{0xBA, 0x00BA },
	{0xBB, 0x00BB },
	{0xBC, 0x00BC },
	{0xBD, 0x00BD },
	{0xBE, 0x00BE },
	{0xBF, 0x00BF },
	{0xC0, 0x00C0 },
	{0xC1, 0x00C1 },
	{0xC2, 0x00C2 },
	{0xC3, 0x00C3 },
	{0xC4, 0x00C4 },
	{0xC5, 0x00C5 },
	{0xC6, 0x00C6 },
	{0xC7, 0x00C7 },
	{0xC8, 0x00C8 },
	{0xC9, 0x00C9 },
	{0xCA, 0x00CA },
	{0xCB, 0x00CB },
	{0xCC, 0x00CC },
	{0xCD, 0x00CD },
	{0xCE, 0x00CE },
	{0xCF, 0x00CF },
	{0xD0, 0x011E },
	{0xD1, 0x00D1 },
	{0xD2, 0x00D2 },
	{0xD3, 0x00D3 },
	{0xD4, 0x00D4 },
	{0xD5, 0x00D5 },
	{0xD6, 0x00D6 },
	{0xD7, 0x00D7 },
	{0xD8, 0x00D8 },
	{0xD9, 0x00D9 },
	{0xDA, 0x00DA },
	{0xDB, 0x00DB },
	{0xDC, 0x00DC },
	{0xDD, 0x0130 },
	{0xDE, 0x015E },
	{0xDF, 0x00DF },
	{0xE0, 0x00E0 },
	{0xE1, 0x00E1 },
	{0xE2, 0x00E2 },
	{0xE3, 0x00E3 },
	{0xE4, 0x00E4 },
	{0xE5, 0x00E5 },
	{0xE6, 0x00E6 },
	{0xE7, 0x00E7 },
	{0xE8, 0x00E8 },
	{0xE9, 0x00E9 },
	{0xEA, 0x00EA },
	{0xEB, 0x00EB },
	{0xEC, 0x00EC },
	{0xED, 0x00ED },
	{0xEE, 0x00EE },
	{0xEF, 0x00EF },
	{0xF0, 0x011F },
	{0xF1, 0x00F1 },
	{0xF2, 0x00F2 },
	{0xF3, 0x00F3 },
	{0xF4, 0x00F4 },
	{0xF5, 0x00F5 },
	{0xF6, 0x00F6 },
	{0xF7, 0x00F7 },
	{0xF8, 0x00F8 },
	{0xF9, 0x00F9 },
	{0xFA, 0x00FA },
	{0xFB, 0x00FB },
	{0xFC, 0x00FC },
	{0xFD, 0x0131 },
	{0xFE, 0x015F },
	{0xFF, 0x00FF },
	
	*/

