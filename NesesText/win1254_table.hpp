﻿#include <map>
#include <tuple>



//win1254 hex --  unicode code point hex -- utf8 hex 
std::map<unsigned char, std::tuple<char16_t, char32_t>> win1254map
{
	{0x80, {0x20AC, 0xE282AC} },		//  €	//  Euro Sign
	{0x81, {0xFFFF, 0xEFBFBF} },		//		//  Undefined Character
	{0x82, {0x201A, 0xE2809A} },		//  ' 	//	SINGLE LOW-9 QUOTATION MARK
	{0x83, {0x0192, 0xC692} },			//  ƒ 	//	LATIN SMALL LETTER F WITH HOOK
	{0x84, {0x201E, 0xE2809E} },		//  „ 	//	DOUBLE LOW-9 QUOTATION MARK
	{0x85, {0x2026, 0xE280A6} },		//  … 	//	HORIZONTAL ELLIPSIS
	{0x86, {0x2020, 0xE280A0} },		//  †	//	DAGGER
	{0x87, {0x2021, 0xE280A1} },		// 	‡	//	DOUBLE DAGGER
	{0x88, {0x02C6, 0xCB86} },			// 	ˆ	//	MODIFIER LETTER CIRCUMFLEX ACCENT
	{0x89, {0x2030, 0xE280B0} },		// 	‰	//	PER MILLE SIGN
	{0x8A, {0x0160, 0xC5A0} },			// 	Š	//	LATIN CAPITAL LETTER S WITH CARON
	{0x8B, {0x2039, 0xE280B9} },		// 	‹	//	Single Left-Pointing Angle Quotation Mark
	{0x8C, {0x0152, 0xC592} },			// 	Œ	//	Latin Capital Ligature Oe
	{0x8D, {0xFFFF, 0xEFBFBF} },		// 		//	Undefined Character
	{0x8E, {0xFFFF, 0xEFBFBF} },		// 		//	Undefined Character
	{0x8F, {0xFFFF, 0xEFBFBF} },		// 		//	Undefined Character
	{0x90, {0xFFFF, 0xEFBFBF} },		// 		//	Undefined Character
	{0x91, {0x2018, 0xE28098} },		// 	‘	//	Left Single Quotation Mark
	{0x92, {0x2019, 0xE28099} },		// 	’	//	Right Single Quotation Mark
	{0x93, {0x201C, 0xE2809C} },		// 	“	//	Left Double Quotation Mark
	{0x94, {0x201D, 0xE2809D} },		// 	”	//	Right Double Quotation Mark
	{0x95, {0x2022, 0xE280A2} },		// 	•	//	Bullet
	{0x96, {0x2013, 0xE28093} },		// 	–	//	En Dash
	{0x97, {0x2014, 0xE28094} },		// 	—	//	Em Dash
	{0x98, {0x02DC, 0xCB9C} },			// 	˜	//	Small Tilde
	{0x99, {0x2122, 0xE284A2} },		// 	™	//	Trade Mark Sign
	{0x9A, {0x0161, 0xC5A1} },			// 	š	//	Latin Small Letter S with Caron
	{0x9B, {0x203A, 0xE280BA} },		// 	›	//	Single Right-Pointing Angle Quotation Mark
	{0x9C, {0x0153, 0xC593} },			// 	œ	//	Latin Small Ligature Oe
	{0x9D, {0xFFFF, 0xEFBFBF} },		// 		//	Undefined Character
	{0x9E, {0xFFFF, 0xEFBFBF} },		// 		//	Undefined Character
	{0x9F, {0x0178, 0xC5B8} },			// 	Ÿ	//	Latin Capital Letter Y with Diaeresis
	{0xA0, {0x00A0, 0xC2A0} },			// 	 	//	No-Break Space (NBSP)
	{0xA1, {0x00A1, 0xC2A1} },			// 	¡	//	Inverted Exclamation Mark
	{0xA2, {0x00A2, 0xC2A2} },			// 	¢	//	Cent Sign
	{0xA3, {0x00A3, 0xC2A3} },			// 	£	//	Pound Sign
	{0xA4, {0x00A4, 0xC2A4} },			// 	¤	//	Currency Sign
	{0xA5, {0x00A5, 0xC2A5} },			// 	¥	//	Yen Sign
	{0xA6, {0x00A6, 0xC2A6} },			// 	¦	//	Broken Bar
	{0xA7, {0x00A7, 0xC2A7} },			// 	§	//	Section Sign
	{0xA8, {0x00A8, 0xC2A8} },			// 	¨	//	Diaeresis
	{0xA9, {0x00A9, 0xC2A9} },			// 	©	//	Copyright Sign
	{0xAA, {0x00AA, 0xC2AA} },			// 	ª	//	Feminine Ordinal Indicator
	{0xAB, {0x00AB, 0xC2AB} },			// 	«	//	Left-pointing Double Angle Quotation Mark
	{0xAC, {0x00AC, 0xC2AC} },			// 	¬	//	Not Sign
	{0xAD, {0x00AD, 0xC2AD} },			// 		//	Soft Hyphen
	{0xAE, {0x00AE, 0xC2AE} },			// 	®	//	Registered Sign
	{0xAF, {0x00AF, 0xC2AF} },			// 	¯	//	Macron
	{0xB0, {0x00B0, 0xC2B0} },			// 	Ÿ	//	Degree Sign
	{0xB1, {0x00B1, 0xC2B1} },			// 	±	//	Plus-minus Sign
	{0xB2, {0x00B2, 0xC2B2} },			// 	²	//	Superscript Two
	{0xB3, {0x00B3, 0xC2B3} },			// 	³	//	Superscript Three
	{0xB4, {0x00B4, 0xC2B4} },			// 	´	//	Acute Accent
	{0xB5, {0x00B5, 0xC2B5} },			// 	µ	//	Micro Sign
	{0xB6, {0x00B6, 0xC2B6} },			// 	¶	//	Pilcrow Sign
	{0xB7, {0x00B7, 0xC2B7} },			// 	·	//	Middle Dot
	{0xB8, {0x00B8, 0xC2B8} },			// 	¸	//	Cedilla
	{0xB9, {0x00B9, 0xC2B9} },			// 	¹	//	Superscript One
	{0xBA, {0x00BA, 0xC2BA} },			// 	º	//	Masculine Ordinal Indicator
	{0xBB, {0x00BB, 0xC2BB} },			// 	»	//	Right-pointing Double Angle Quotation Mark
	{0xBC, {0x00BC, 0xC2BC} },			// 	¼	//	Vulgar Fraction One Quarter
	{0xBD, {0x00BD, 0xC2BD} },			// 	½	//	Vulgar Fraction One Half
	{0xBE, {0x00BE, 0xC2BE} },			// 	¾	//	Vulgar Fraction Three Quarters
	{0xBF, {0x00BF, 0xC2BF} },			// 	¿	//	Inverted Question Mark
	{0xC0, {0x00C0, 0xC380} },			// 	À	//	Latin Capital Letter A With Grave
	{0xC1, {0x00C1, 0xC381} },			// 	Á	//	Latin Capital Letter A With Acute
	{0xC2, {0x00C2, 0xC382} },			// 	Â	//	Latin Capital Letter A With Circumflex
	{0xC3, {0x00C3, 0xC383} },			// 	Ã	//	Latin Capital Letter A With Tilde
	{0xC4, {0x00C4, 0xC384} },			// 	Ä	//	Latin Capital Letter A With Diaeresis
	{0xC5, {0x00C5, 0xC385} },			// 	Å	//	Latin Capital Letter A With Ring Above
	{0xC6, {0x00C6, 0xC386} },			// 	Æ	//	Latin Capital Letter Ae
	{0xC7, {0x00C7, 0xC387} },			// 	Ç	//	Latin Capital Letter C With Cedilla
	{0xC8, {0x00C8, 0xC388} },			// 	È	//	Latin Capital Letter E With Grave
	{0xC9, {0x00C9, 0xC389} },			// 	É	//	Latin Capital Letter E With Acute
	{0xCA, {0x00CA, 0xC38A} },			// 	Ê	//	Latin Capital Letter E With Circumflex
	{0xCB, {0x00CB, 0xC38B} },			// 	Ë	//	Latin Capital Letter E With Diaeresis
	{0xCC, {0x00CC, 0xC38C} },			// 	Ì	//	Latin Capital Letter I With Grave
	{0xCD, {0x00CD, 0xC38D} },			// 	Í	//	Latin Capital Letter I With Acute
	{0xCE, {0x00CE, 0xC38E} },			// 	Î	//	Latin Capital Letter I With Circumflex
	{0xCF, {0x00CF, 0xC38F} },			// 	Ï	//	Latin Capital Letter I With Diaeresis
	{0xD0, {0x011E, 0xC49E} },			// 	Ğ	//	Latin Capital Letter G with Breve
	{0xD1, {0x00D1, 0xC391} },			// 	Ñ	//	Latin Capital Letter N With Tilde
	{0xD2, {0x00D2, 0xC392} },			// 	Ò	//	Latin Capital Letter O With Grave
	{0xD3, {0x00D3, 0xC393} },			// 	Ó	//	Latin Capital Letter O With Acute
	{0xD4, {0x00D4, 0xC394} },			// 	Ô	//	Latin Capital Letter O With Circumflex
	{0xD5, {0x00D5, 0xC395} },			// 	Õ	//	Latin Capital Letter O With Tilde
	{0xD6, {0x00D6, 0xC396} },			// 	Ö	//	Latin Capital Letter O With Diaeresis
	{0xD7, {0x00D7, 0xC397} },			// 	×	//	Multiplication Sign
	{0xD8, {0x00D8, 0xC398} },			// 	Ø	//	Latin Capital Letter O With Stroke
	{0xD9, {0x00D9, 0xC399} },			// 	Ù	//	Latin Capital Letter U With Grave
	{0xDA, {0x00DA, 0xC39A} },			// 	Ú	//	Latin Capital Letter U With Acute
	{0xDB, {0x00DB, 0xC39B} },			// 	Û	//	Latin Capital Letter U With Circumflex
	{0xDC, {0x00DC, 0xC39C} },			// 	Ü	//	Latin Capital Letter U With Diaeresis
	{0xDD, {0x0130, 0xC4B0} },			// 	İ	//	Latin Capital Letter I with Dot Above
	{0xDE, {0x015E, 0xC59E} },			// 	Ş	//	Latin Capital Letter S with Cedilla
	{0xDF, {0x00DF, 0xC39F} },			// 	ß	//	Latin Small Letter Sharp S
	{0xE0, {0x00E0, 0xC3A0} },			// 	à	//	Latin Small Letter A With Grave
	{0xE1, {0x00E1, 0xC3A1} },			// 	á	//	Latin Small Letter A With Acute
	{0xE2, {0x00E2, 0xC3A2} },			// 	â	//	Latin Small Letter A With Circumflex
	{0xE3, {0x00E3, 0xC3A3} },			// 	ã	//	Latin Small Letter A With Tilde
	{0xE4, {0x00E4, 0xC3A4} },			// 	ä	//	Latin Small Letter A With Diaeresis
	{0xE5, {0x00E5, 0xC3A5} },			// 	å	//	Latin Small Letter A With Ring Above
	{0xE6, {0x00E6, 0xC3A6} },			// 	æ	//	Latin Small Letter Ae
	{0xE7, {0x00E7, 0xC3A7} },			// 	ç	//	Latin Small Letter C With Cedilla
	{0xE8, {0x00E8, 0xC3A8} },			// 	è	//	Latin Small Letter E With Grave
	{0xE9, {0x00E9, 0xC3A9} },			// 	é	//	Latin Small Letter E With Acute
	{0xEA, {0x00EA, 0xC3AA} },			// 	ê	//	Latin Small Letter E With Circumflex
	{0xEB, {0x00EB, 0xC3AB} },			// 	ë	//	Latin Small Letter E With Diaeresis
	{0xEC, {0x00EC, 0xC3AC} },			// 	ì	//	Latin Small Letter I With Grave
	{0xED, {0x00ED, 0xC3AD} },			// 	í	//	Latin Small Letter I With Acute
	{0xEE, {0x00EE, 0xC3AE} },			// 	î	//	Latin Small Letter I With Circumflex
	{0xEF, {0x00EF, 0xC3AF} },			// 	ï	//	Latin Small Letter I With Diaeresis
	{0xF0, {0x011F, 0xC49F} },			// 	ğ	//	Latin Small Letter G with Breve
	{0xF1, {0x00F1, 0xC3B1} },			// 	ñ	//	Latin Small Letter N With Tilde
	{0xF2, {0x00F2, 0xC3B2} },			// 	ò	//	Latin Small Letter O With Grave
	{0xF3, {0x00F3, 0xC3B3} },			// 	ó	//	Latin Small Letter O With Acute
	{0xF4, {0x00F4, 0xC3B4} },			// 	ô	//	Latin Small Letter O With Circumflex
	{0xF5, {0x00F5, 0xC3B5} },			// 	õ	//	Latin Small Letter O With Tilde
	{0xF6, {0x00F6, 0xC3B6} },			// 	ö	//	Latin Small Letter O With Diaeresis
	{0xF7, {0x00F7, 0xC3B7} },			// 	÷	//	Division Sign
	{0xF8, {0x00F8, 0xC3B8} },			// 	ø	//	Latin Small Letter O With Stroke
	{0xF9, {0x00F9, 0xC3B9} },			// 	ù	//	Latin Small Letter U With Grave
	{0xFA, {0x00FA, 0xC3BA} },			// 	ú	//	Latin Small Letter U With Acute
	{0xFB, {0x00FB, 0xC3BB} },			// 	û	//	Latin Small Letter U With Circumflex
	{0xFC, {0x00FC, 0xC3BC} },			// 	ü	//	Latin Small Letter U With Diaeresis
	{0xFD, {0x0131, 0XC4B1} },			// 	ı	//	Latin Small Letter Dotless I
	{0xFE, {0x015F, 0xC59F} },			// 	ş	//	Latin Small Letter S with Cedilla
	{0xFF, {0x00FF, 0xC3BF} },			// 	ÿ	//	Latin Small Letter Y With Diaeresis
	
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

