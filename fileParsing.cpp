#include <iostream>
#include <vector>
#include <cmath>

void parseLidarFromFile(std::string str, long &timestamp, std::vector<long> &vec)
{
    std::vector<long> lidar, aux;
    std::string delimiter = "|", token;
    size_t pos = 0;
	int index_remove = 0, h, m, s;
    if(str.find(delimiter) > str.size())
    {
        delimiter = ",";
    }

    while((pos=str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0,pos);
		//index_remove++;
		//if(index_remove > 2) 
		aux.push_back(atoi(token.c_str()));
        str.erase(0, pos + delimiter.length() );
    }
    aux.push_back(atoi(str.c_str()));
    vec.clear();
    if (aux.size()==1083)
    {
        h = std::floor(aux[1]/10000);
        m = std::floor(aux[1]/100) - 100*h;
        s = aux[1] - 10000*h - 100*m;
        std::cout << "\nh: " << h << " m: " << m << " s: " << s;
        timestamp = (h*3600 + m*60 + s)*1000 + aux[2]  ;
        for (int i = 3; i < aux.size(); i++ )
        {
            vec.push_back(aux[i]);
        }
    }
    else if(aux.size()==1081)
    {
        timestamp = aux[0];
        for (int i = 1; i < aux.size(); i++ )
        {
            vec.push_back(aux[i]);
        }

    }
    //lidar.pop_back();
    //return lidar;
    //return aux;
}

int main(int argc, char* argv[])
{
    std::string a1 = "20170922|100820|59|1546|1546|1546|1546|1546|1603|2318|2379|2520|2523|2523|2520|1233|1224|1224|1216|1219|1224|1227|1227|1272|1272|1370|1449|1450|1450|1449|1439|1369|1349|1342|1342|1348|1349|1384|1939|2223|2261|5008|5008|4974|4974|4948|4941|4941|4937|4936|4891|4811|4811|4811|4805|4805|4697|4677|2126|2122|2122|2117|2101|2116|2116|2116|2119|2131|2280|2280|2322|2280|2264|2231|2143|2087|2074|2069|2061|2061|2061|4332|4413|4413|4413|2068|2056|2049|2034|1999|1999|1999|2004|2016|2016|2020|2022|5856|5856|5790|5790|5859|6062|7484|7496|8264|8264|8160|7262|4588|4588|4588|7152|7152|4295|4295|4293|4293|4295|4301|4301|4307|4307|4301|4285|4285|4285|4437|5026|5049|5094|5094|4246|4190|4178|4190|4190|4170|4170|4188|4188|4203|4258|4494|5113|5113|4703|4359|4312|4067|4028|4008|4008|4008|6519|6519|4174|4173|1873|1818|1812|1812|1812|1812|1848|1862|1863|1863|1877|1877|1866|1866|1839|1817|1544|1173|1102|1092|1092|1092|1098|1098|1098|1098|1098|1085|1084|1072|1064|1060|998|996|887|687|635|448|376|353|352|343|343|333|333|333|337|350|350|353|350|347|347|347|347|347|347|353|364|340|364|367|415|453|542|951|6571|6571|4457|4444|4443|4418|1307|1236|1233|1226|1219|1226|1226|1226|1215|1227|1227|1363|1363|1363|1287|1284|1284|1286|1287|1299|1706|1934|1940|1940|1942|1942|6953|7015|7120|7135|7135|2120|2096|2068|2065|2041|2041|1969|1964|1440|1374|1254|1228|1218|1218|1222|1222|1226|1238|1321|1336|1338|1338|1338|1417|1417|1417|1371|1369|1328|1326|1310|1283|1278|1266|1264|952|581|495|485|485|482|458|455|455|454|454|455|459|459|459|456|450|450|450|470|476|2418|2418|2418|1594|1516|1516|1516|1568|2264|2388|2394|2394|2388|1503|1278|1278|1277|1278|1281|1284|1284|1284|1284|543|532|532|529|529|532|529|529|529|529|529|529|529|513|513|510|505|505|505|505|505|505|505|494|511|510|511|532|541|1447|1798|1892|2818|2818|2818|717|690|690|707|707|690|677|677|677|689|693|693|693|693|693|698|704|832|832|866|866|833|826|750|670|651|651|651|660|667|667|670|685|713|776|794|804|804|794|792|792|784|792|798|798|798|798|753|669|654|652|652|651|651|649|642|642|641|641|653|659|664|692|741|845|851|851|851|678|677|673|673|673|672|651|651|652|651|652|654|665|680|684|861|1062|1108|1182|1248|1347|1376|1376|1423|1480|1480|1480|1350|1319|1319|1319|1342|1480|1491|1491|1493|1493|1493|1493|1526|1547|1792|1792|1792|1517|1517|1517|1518|1561|1614|1870|1942|1942|1942|1929|1912|1912|1912|1926|1944|2040|2196|2216|2216|2216|2235|2949|3006|3124|4167|4464|4464|4473|4464|4464|4451|4473|4582|4994|5170|5961|5992|5992|5950|5947|5931|5781|4922|4875|4875|4801|4801|4797|4801|4279|4279|4279|4436|4448|4626|4513|4513|4255|3318|3247|3247|3247|3247|3229|2691|2657|2647|2602|2590|2590|2532|2435|1799|1779|1755|1749|1748|1699|1621|1585|1571|1571|1571|1613|1812|1830|1830|1830|1770|1769|1768|1621|1590|1574|1574|1574|1574|1484|1484|1484|1484|1484|1510|1510|1510|1478|1457|1457|1457|1457|1457|1457|1161|1158|1116|1115|1083|1071|1015|1014|1014|1015|1017|1035|1035|1040|1040|1022|1016|993|993|996|996|987|950|779|697|695|688|688|697|731|745|796|946|947|947|946|945|799|763|757|757|757|757|749|749|761|764|821|935|2408|2420|2469|2469|2512|2256|2229|2149|2099|1162|1052|1041|1035|1030|1023|1016|1015|1005|1013|1013|1013|1013|1013|681|677|672|669|669|661|663|661|663|661|661|661|672|685|692|731|731|731|716|714|714|714|723|799|1541|1659|1659|1659|1521|1495|1495|1495|1495|1412|623|585|561|561|554|545|542|542|541|540|540|540|540|546|546|548|548|553|566|566|566|544|544|543|543|555|1151|1303|1328|1364|1424|1479|1483|1492|1489|1504|1509|1509|1489|1484|1420|1420|1420|1445|1447|1447|1445|1432|1432|1432|1444|2291|2291|2291|2241|2241|2241|2252|2263|2277|2277|2252|2169|2113|482|474|472|466|466|472|473|473|473|465|465|465|465|430|475|482|3046|3046|3084|3046|3041|2646|2616|2180|2171|2170|2170|2170|2364|2364|2364|1261|1215|1214|1214|1207|1199|1207|1218|1246|1248|1370|1990|2028|2031|2083|4246|4388|4396|6711|6711|2840|2840|2840|2872|3691|3691|3691|449|434|416|424|430|424|416|413|413|413|426|426|426|412|405|402|402|400|400|400|415|417|417|417|420|420|420|433|434|2203|2284|2294|2296|2296|2321|2396|2683|2683|2683|2683|2683|5660|5660|3435|3410|3408|1976|1963|1929|1929|1278|1202|1200|1200|1200|1204|1206|1206|1210|1210|1216|2000|2000|2000|1987|1985|1982|1982|1982|1982|1982|8041|8041|6397|6370|6151|6123|5676|5676|5347|5096|5025|4958|4927|4303|4303|4303|4318|4867|4867|4913|4955|4955|4955|4955|3587|3451|3451|3451|3460|5771|5771|3346|2856|2856|2856|5024|5024|4491|4423|4412|2824|2824|2822|2822|2822|2810|2793|2774|2768|2768|2774|2778|2803|2803|2803|2766|2766|2766|3567|3567|3567|3440|2211|2201|2201|2203|2211|2203|2203|2184|2141|2141|2141|2696|2899|2972|2972|2972|2972|3919|4092|4092|3919|2239|2203|2185|2185|2185|2203|2222|2312|2342|2342|2370|2370|2370|2292|2292|2236|2216|2188|2124|2124|2124|2174|2174|2174|2174|2179|2255|2256|2266|2283|2293|2293|2293|1488|1481|1449|1449|1449|1453|1473|1488|2487|2487|2487|2487|2487|2679|4076|4076|4076|2544|2528|1656|1516|1507|1507|1507|1569|1639|1650|1664|1682|1758|2666|2666|2666|2505|1685|1600|1580|1572|1549|1545|1531|1501|1490|1469|1469|1469|1494|1546|1560|1560|1560|1591|1904|1904|1904|1904|1891|1886|1857|1728|1701|1701|1701|1804|1811|2926|2926|2926";
    std::string a2 = "1814021,1691,1813,1813,1813,1207,1146,1131,1106,1105,1087,1080,1080,1073,1073,1072,1072,1072,1070,1064,1064,1066,1058,1060,1066,1060,1060,1067,1070,1070,1080,1083,1088,1111,1118,1164,1223,1346,1346,1346,1346,1346,1356,1356,1356,1349,1349,1349,1359,1661,1965,1965,1965,1678,1678,1678,1884,1968,2198,2219,2265,2265,2265,1443,1443,1409,1409,1402,1409,1349,1323,1109,796,796,796,2219,2551,2551,2551,815,680,557,546,546,546,556,556,556,556,554,553,282,267,226,215,226,221,226,221,228,228,228,230,231,231,262,271,271,271,268,268,266,266,258,266,275,275,275,289,293,289,293,293,296,284,284,284,303,295,303,307,313,323,377,961,1034,1192,1209,1209,1224,1209,1186,1183,1183,1183,1175,1172,1172,1169,1148,1146,1124,1097,1050,807,700,684,672,672,672,680,688,713,852,852,852,852,598,598,598,600,605,607,607,607,587,587,587,571,567,560,560,560,897,922,922,914,914,911,911,914,1090,1121,1134,1136,1136,1136,1136,1136,1111,840,803,803,803,813,829,1257,1287,1316,1657,1657,1657,788,788,788,1146,1206,1212,1212,1265,1299,1299,1299,1187,1186,1163,1158,1096,1069,1064,1053,846,756,547,436,407,405,380,380,374,379,379,372,368,372,372,377,377,377,377,377,390,429,474,474,474,452,437,437,437,437,428,437,433,428,433,435,435,439,453,494,512,542,545,585,611,630,630,631,636,658,697,697,697,580,466,441,437,417,414,407,400,389,389,381,381,381,381,386,405,405,405,400,400,400,444,492,501,524,549,570,790,790,790,558,528,527,526,526,526,526,526,526,526,526,526,526,510,451,442,440,440,440,440,440,449,458,479,571,583,590,590,583,552,543,540,540,538,538,531,538,531,531,531,534,534,560,560,560,560,560,576,674,837,876,876,876,864,834,812,781,729,549,502,489,483,473,473,475,471,471,475,472,472,479,479,480,539,585,612,612,612,599,529,504,481,481,474,474,485,509,632,632,652,655,652,652,652,660,660,684,726,726,726,726,726,738,752,752,752,648,648,648,671,740,740,740,740,731,730,730,712,712,712,766,819,863,863,881,964,1052,1280,1280,1280,1117,964,944,932,913,913,913,913,982,1016,1052,1094,1233,1239,1239,1239,949,933,926,931,931,933,957,968,1047,1314,1353,1353,1353,1190,1131,1131,1131,768,1002,1081,1081,1081,1091,1091,1139,1139,1310,1405,1405,1405,871,848,834,834,823,808,808,844,1248,1266,1276,1276,1502,1502,1502,1457,1325,1259,1258,1259,1325,1077,350,53,51,49,49,4,4,4,4,4,4,4,4,4,4,4,50,50,64,1283,1371,1371,1283,1283,51,51,51,45,40,40,40,40,46,54,54,56,1653,1680,1922,2124,2139,2158,2195,2195,2227,2227,2195,1453,1488,1488,1453,1442,1291,1283,1087,1028,1036,1036,1036,1041,1046,1137,1137,1137,1132,1093,958,798,774,645,578,449,446,446,449,451,451,452,452,452,461,470,470,470,470,470,467,467,467,473,473,482,519,710,758,760,769,779,880,905,905,905,897,852,852,873,856,856,856,855,842,839,795,788,763,724,724,717,707,674,672,671,671,668,668,665,668,668,668,670,709,709,709,680,672,645,643,643,636,635,635,631,622,610,608,605,603,595,577,559,535,505,495,487,475,475,475,491,491,491,493,489,489,493,535,581,581,581,581,581,579,582,585,585,599,602,639,648,649,649,649,659,676,659,659,506,450,408,405,401,401,401,401,398,392,392,392,387,387,395,401,404,420,422,445,523,558,558,558,543,512,464,422,397,360,359,349,349,349,349,349,347,353,353,355,401,401,401,389,379,359,356,345,343,344,344,343,343,342,333,333,342,342,348,351,352,352,365,386,400,497,562,563,594,610,610,610,622,622,633,644,649,690,694,724,777,806,861,887,954,963,963,979,979,980,955,980,980,1032,1235,2167,2173,2173,2173,327,301,294,292,274,259,253,239,238,237,237,188,181,168,162,155,155,153,153,153,153,151,151,143,145,143,141,143,145,151,157,157,151,157,158,163,165,168,168,181,211,228,236,257,307,336,356,356,356,350,316,310,302,300,297,296,296,293,293,300,300,299,300,302,309,318,348,380,434,479,540,547,547,544,544,529,529,529,695,695,695,574,571,571,571,571,454,413,411,394,394,394,394,388,382,380,377,367,366,340,335,335,335,332,330,330,329,330,330,336,336,336,328,336,329,329,337,338,337,337,332,327,327,327,324,327,326,326,331,340,340,341,355,356,356,356,334,334,321,327,334,327,327,342,343,356,367,367,367,357,367,367,363,363,367,365,363,365,367,365,368,368,368,368,368,370,360,358,352,351,349,321,298,259,231,229,207,201,198,198,198,196,196,197,200,201,203,218,243,288,293,297,307,327,352,391,409,472,472,472,198,195,195,181,181,196,231,231,231,244,243,223,243,244,246,246,246,239,239,239,245,246,246,248,248,235,231,235,235,247,247,247,247,237,237,239,239,239,239,243,248,248,248,248,246,246,246,245,245,242,242,249,249,249,249,249,247,247,247,248,247,248,248,259,304,321,1944,1953,1959,1959,2164,2295,2364,2441,2472,2472,2472,2441,2472,2495,2435,2435,2435,1697,1689";
    std::vector<long> lidar;
    long timestamp;
    parseLidarFromFile(a1, timestamp, lidar);
    std::cout << "\nSize: " << lidar.size() << " [0]: " << lidar[0] << " [" << lidar.size()-1 << "]: " << lidar.back() << std::endl << timestamp << std::endl; 
    parseLidarFromFile(a2, timestamp, lidar);
    std::cout << "\nSize: " << lidar.size() << " [0]: " << lidar[0] << " [" << lidar.size()-1 << "]: " << lidar.back() << std::endl << timestamp << std::endl; 

}