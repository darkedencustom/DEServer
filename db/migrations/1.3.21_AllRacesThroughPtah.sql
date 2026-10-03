-- 1.3.21 every race gear chain through Ptah, articles in the matching TunningItemInfo table.
-- Names are the v.918 item names. Inferno/Legendry/Article is the tuner suffix only.
-- Last new row points at itself. ADV steps continue from the current chain end to 91.
SET NAMES latin1;

-- SwordInfo Sword Emperor type 22 ADV 31 -> 91
UPDATE `SwordInfo` SET NextItemType=23 WHERE ItemType=22;
INSERT INTO `SwordInfo` VALUES (23, 24, '노퉁크', 'Nothung', 10800000, 6, 1, 0, 59000, 49, 64, 55, 1, 5, '(ADV,41)', 59000, 191, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (79, '노퉁크 인페르노', 'Nothung Inferno', 10800000, 6, 14, 23, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `SwordInfo` VALUES (24, 25, '에스터크', 'Estuck', 14580000, 6, 1, 0, 59000, 53, 69, 55, 1, 5, '(ADV,51)', 59000, 201, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (80, '에스터크 인페르노', 'Estuck Inferno', 14580000, 6, 14, 24, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `SwordInfo` VALUES (25, 26, '그리드 칼라드볼그', 'Greed Caladbolg', 19683000, 6, 1, 0, 59000, 57, 75, 55, 1, 5, '(ADV,61)', 59000, 211, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (81, '그리드 칼라드볼그 인페르노', 'Greed Caladbolg Inferno', 19683000, 6, 14, 25, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `SwordInfo` VALUES (26, 27, '레바테인', 'Levatein', 26572050, 6, 1, 0, 59000, 62, 81, 55, 1, 5, '(ADV,71)', 59000, 221, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (82, '레바테인 인페르노', 'Levatein Inferno', 26572050, 6, 14, 26, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `SwordInfo` VALUES (27, 28, '게부라 소드', 'Geburah Sword', 35872267, 6, 1, 0, 59000, 67, 88, 55, 1, 5, '(ADV,81)', 59000, 231, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (83, '게부라 소드 인페르노', 'Geburah Sword Inferno', 35872267, 6, 14, 27, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `SwordInfo` VALUES (28, 28, '소드 블래스터', 'Sword Blaster', 48427560, 6, 1, 0, 59000, 72, 95, 55, 1, 5, '(ADV,91)', 59000, 241, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (84, '소드 블래스터 인페르노', 'Sword Blaster Inferno', 48427560, 6, 14, 28, 100, '(ADV,91)', '', 0, 0);

-- BladeInfo Queen's Cutter type 22 ADV 41 -> 91
UPDATE `BladeInfo` SET NextItemType=23 WHERE ItemType=22;
INSERT INTO `BladeInfo` VALUES (23, 24, '데스 아고니', 'Death Agony', 10800000, 6, 1, 0, 63000, 63, 83, 55, 1, 5, '(ADV,51)', 63000, 201, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (85, '데스 아고니 인페르노', 'Death Agony Inferno', 10800000, 6, 15, 23, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `BladeInfo` VALUES (24, 25, '아슈켈론', 'Ascalon', 14580000, 6, 1, 0, 63000, 68, 89, 55, 1, 5, '(ADV,61)', 63000, 211, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (86, '아슈켈론 인페르노', 'Ascalon Inferno', 14580000, 6, 15, 24, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `BladeInfo` VALUES (25, 26, '그리드 플랑베르주', 'Greed Flamberge', 19683000, 6, 1, 0, 63000, 74, 96, 55, 1, 5, '(ADV,71)', 63000, 221, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (87, '그리드 플랑베르주 인페르노', 'Greed Flamberge Inferno', 19683000, 6, 15, 25, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `BladeInfo` VALUES (26, 27, '갈라틴', 'Gallatin', 26572050, 6, 1, 0, 63000, 80, 104, 55, 1, 5, '(ADV,81)', 63000, 231, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (88, '갈라틴 인페르노', 'Gallatin Inferno', 26572050, 6, 15, 26, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `BladeInfo` VALUES (27, 27, '티파레트 블레이드', 'Tiphreth Blade', 35872267, 6, 1, 0, 63000, 86, 113, 55, 1, 5, '(ADV,91)', 63000, 241, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (89, '티파레트 블레이드 인페르노', 'Tiphreth Blade Inferno', 35872267, 6, 15, 27, 100, '(ADV,91)', '', 0, 0);

-- ARInfo L-108 Ravage type 22 ADV 31 -> 91
UPDATE `ARInfo` SET NextItemType=23 WHERE ItemType=22;
INSERT INTO `ARInfo` VALUES (23, 24, 'L-208 캔슬러', 'L-208 Canceler', 9450000, 6, 1, 0, 36000, 42, 49, 64, 8, 7, '(ADV,41)', 16, 191, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (90, 'L-208 캔슬러 인페르노', 'L-208 Canceler Inferno', 9450000, 6, 22, 23, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `ARInfo` VALUES (24, 25, 'Kurtz H. Temecula', 'Kurtz H. Temecula', 12757500, 6, 1, 0, 36000, 45, 53, 64, 8, 7, '(ADV,51)', 16, 201, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (91, 'Kurtz H. Temecula 인페르노', 'Kurtz H. Temecula Inferno', 12757500, 6, 22, 24, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `ARInfo` VALUES (25, 26, '그리드 SCA-DA', 'Greed SCA-DA', 17222625, 6, 1, 0, 36000, 49, 57, 64, 8, 7, '(ADV,61)', 16, 211, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (92, '그리드 SCA-DA 인페르노', 'Greed SCA-DA Inferno', 17222625, 6, 22, 25, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `ARInfo` VALUES (26, 27, '자칼', 'Jackal', 23250543, 6, 1, 0, 36000, 53, 62, 64, 8, 7, '(ADV,71)', 16, 221, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (93, '자칼 인페르노', 'Jackal Inferno', 23250543, 6, 22, 26, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `ARInfo` VALUES (27, 28, '네트아크 HK417', 'Netreth HK417', 31388233, 6, 1, 0, 36000, 57, 67, 64, 8, 7, '(ADV,81)', 16, 231, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (94, '네트아크 HK417 인페르노', 'Netreth HK417 Inferno', 31388233, 6, 22, 27, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `ARInfo` VALUES (28, 28, 'MK-A1 제노사이드', 'MK-A1 Genocid', 42374114, 6, 1, 0, 36000, 61, 72, 64, 8, 7, '(ADV,91)', 16, 241, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (95, 'MK-A1 제노사이드 인페르노', 'MK-A1 Genocid Inferno', 42374114, 6, 22, 28, 100, '(ADV,91)', '', 0, 0);

-- SRInfo MK-300 Eraser type 22 ADV 31 -> 91
UPDATE `SRInfo` SET NextItemType=23 WHERE ItemType=22;
INSERT INTO `SRInfo` VALUES (23, 24, 'MK-400 마하 스플리터', 'MK-400 Mach Splitter', 10800000, 6, 1, 0, 36000, 60, 72, 64, 9, 7, '(ADV,41)', 16, 191, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (96, 'MK-400 마하 스플리터 인페르노', 'MK-400 Mach Splitter Inferno', 10800000, 6, 23, 23, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `SRInfo` VALUES (24, 25, '그리드 M200 NYX', 'Greed M200 NYX', 14580000, 6, 1, 0, 36000, 65, 78, 64, 9, 7, '(ADV,51)', 16, 201, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (97, '그리드 M200 NYX 인페르노', 'Greed M200 NYX Inferno', 14580000, 6, 23, 24, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `SRInfo` VALUES (25, 26, '악켈테', 'Ackellte', 19683000, 6, 1, 0, 36000, 70, 84, 64, 9, 7, '(ADV,61)', 16, 211, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (98, '악켈테 인페르노', 'Ackellte Inferno', 19683000, 6, 23, 25, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `SRInfo` VALUES (26, 27, '루드밀라 헤카테', 'Lyudmila Hekate', 26572050, 6, 1, 0, 36000, 76, 91, 64, 9, 7, '(ADV,71)', 16, 221, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (99, '루드밀라 헤카테 인페르노', 'Lyudmila Hekate Inferno', 26572050, 6, 23, 26, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `SRInfo` VALUES (27, 28, '호드 RT-20', 'Hod RT-20', 35872267, 6, 1, 0, 36000, 82, 98, 64, 9, 7, '(ADV,81)', 16, 231, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (100, '호드 RT-20 인페르노', 'Hod RT-20 Inferno', 35872267, 6, 23, 27, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `SRInfo` VALUES (28, 28, '저지먼트 불렛', 'Judgement Bullet', 48427560, 6, 1, 0, 36000, 88, 106, 64, 9, 7, '(ADV,91)', 16, 241, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (101, '저지먼트 불렛 인페르노', 'Judgement Bullet Inferno', 48427560, 6, 23, 28, 100, '(ADV,91)', '', 0, 0);

-- SGInfo USAS-12 Auto type 20 ADV 11 -> 91
UPDATE `SGInfo` SET NextItemType=21 WHERE ItemType=20;
INSERT INTO `SGInfo` VALUES (21, 22, '파멸의 공포(SG)', 'Fear of ruin(SG)', 8100000, 6, 1, 0, 34000, 34, 41, 64, 6, 9, '(ADV,21)', 14, 171, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (102, '파멸의 공포(SG) 인페르노', 'Fear of ruin(SG) Inferno', 8100000, 6, 20, 21, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `SGInfo` VALUES (22, 23, 'IS-100 지그', 'IS-100 ZIG', 10935000, 6, 1, 0, 34000, 37, 44, 64, 6, 9, '(ADV,31)', 14, 181, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (103, 'IS-100 지그 인페르노', 'IS-100 ZIG Inferno', 10935000, 6, 20, 22, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `SGInfo` VALUES (23, 24, 'M-INTER', 'M-INTER', 14762250, 6, 1, 0, 34000, 40, 47, 64, 6, 9, '(ADV,41)', 14, 191, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (104, 'M-INTER 인페르노', 'M-INTER Inferno', 14762250, 6, 20, 23, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `SGInfo` VALUES (24, 25, 'B-INTER', 'B-INTER', 19929037, 6, 1, 0, 34000, 43, 51, 64, 6, 9, '(ADV,51)', 14, 201, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (105, 'B-INTER 인페르노', 'B-INTER Inferno', 19929037, 6, 20, 24, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `SGInfo` VALUES (25, 26, 'VK-45 드래곤플라이', 'VK-45 Dragonfly', 26904199, 6, 1, 0, 34000, 47, 55, 64, 6, 9, '(ADV,61)', 14, 211, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (106, 'VK-45 드래곤플라이 인페르노', 'VK-45 Dragonfly Inferno', 26904199, 6, 20, 25, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `SGInfo` VALUES (26, 27, 'MD-9 스콜피언', 'MD-9 Scorpion', 36320668, 6, 1, 0, 34000, 50, 60, 64, 6, 9, '(ADV,71)', 14, 221, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (107, 'MD-9 스콜피언 인페르노', 'MD-9 Scorpion Inferno', 36320668, 6, 20, 26, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `SGInfo` VALUES (27, 27, 'Smith 바이러스', 'Smith VERUS', 49032901, 6, 1, 0, 34000, 54, 65, 64, 6, 9, '(ADV,91)', 14, 241, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (108, 'Smith 바이러스 인페르노', 'Smith VERUS Inferno', 49032901, 6, 20, 27, 100, '(ADV,91)', '', 0, 0);

-- SMGInfo Thomson type 20 ADV 11 -> 91
UPDATE `SMGInfo` SET NextItemType=21 WHERE ItemType=20;
INSERT INTO `SMGInfo` VALUES (21, 21, '파멸의 공포(SMG)', 'Fear of ruin(SMG)', 8100000, 6, 1, 0, 34000, 31, 35, 64, 7, 9, '(ADV,91)', 14, 241, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (109, '파멸의 공포(SMG) 인페르노', 'Fear of ruin(SMG) Inferno', 8100000, 6, 21, 21, 100, '(ADV,91)', '', 0, 0);

-- CrossInfo Cross Of Nazareth type 20 ADV 31 -> 91
UPDATE `CrossInfo` SET NextItemType=21 WHERE ItemType=20;
INSERT INTO `CrossInfo` VALUES (21, 22, '파르지팔', 'Parsifal', 10800000, 6, 1, 0, 43000, 37, 55, 0, 1, 7, '(ADV,41)', 43000, 191, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (110, '파르지팔 인페르노', 'Parsifal Inferno', 10800000, 6, 17, 21, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `CrossInfo` VALUES (22, 23, '헤르메스의 크로스', 'Hermes Cross', 14580000, 6, 1, 0, 43000, 40, 59, 0, 1, 7, '(ADV,51)', 43000, 201, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (111, '헤르메스의 크로스 인페르노', 'Hermes Cross Inferno', 14580000, 6, 17, 22, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `CrossInfo` VALUES (23, 24, '그리드 크루시스', 'Greed Crusis', 19683000, 6, 1, 0, 43000, 44, 64, 0, 1, 7, '(ADV,61)', 43000, 211, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (112, '그리드 크루시스 인페르노', 'Greed Crusis Inferno', 19683000, 6, 17, 23, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `CrossInfo` VALUES (24, 25, '비자야', 'Vjaya', 26572050, 6, 1, 0, 43000, 47, 69, 0, 1, 7, '(ADV,71)', 43000, 221, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (113, '비자야 인페르노', 'Vjaya Inferno', 26572050, 6, 17, 24, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `CrossInfo` VALUES (25, 26, '케세드 크로스', 'Chesed Cross', 35872267, 6, 1, 0, 43000, 51, 74, 0, 1, 7, '(ADV,81)', 43000, 231, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (114, '케세드 크로스 인페르노', 'Chesed Cross Inferno', 35872267, 6, 17, 25, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `CrossInfo` VALUES (26, 26, '광휘의 십자가', 'Brightness Cross', 48427560, 6, 1, 0, 43000, 55, 80, 0, 1, 7, '(ADV,91)', 43000, 241, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (115, '광휘의 십자가 인페르노', 'Brightness Cross Inferno', 48427560, 6, 17, 26, 100, '(ADV,91)', '', 0, 0);

-- MaceInfo Mjolnir type 20 ADV 31 -> 91
UPDATE `MaceInfo` SET NextItemType=21 WHERE ItemType=20;
INSERT INTO `MaceInfo` VALUES (21, 22, '케라우노스', 'Keraunos', 10800000, 6, 1, 0, 43000, 37, 56, 0, 1, 7, '(ADV,41)', 43000, 191, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (116, '케라우노스 인페르노', 'Keraunos Inferno', 10800000, 6, 35, 21, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `MaceInfo` VALUES (22, 23, '포텐셜 임펙트', 'Potential Impact', 14580000, 6, 1, 0, 43000, 40, 60, 0, 1, 7, '(ADV,51)', 43000, 201, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (117, '포텐셜 임펙트 인페르노', 'Potential Impact Inferno', 14580000, 6, 35, 22, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `MaceInfo` VALUES (23, 24, '그리드 간반테인', 'Greed Ganbantein', 19683000, 6, 1, 0, 43000, 44, 65, 0, 1, 7, '(ADV,61)', 43000, 211, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (118, '그리드 간반테인 인페르노', 'Greed Ganbantein Inferno', 19683000, 6, 35, 23, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `MaceInfo` VALUES (24, 25, '아야무르', 'Ayamur', 26572050, 6, 1, 0, 43000, 47, 70, 0, 1, 7, '(ADV,71)', 43000, 221, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (119, '아야무르 인페르노', 'Ayamur Inferno', 26572050, 6, 35, 24, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `MaceInfo` VALUES (25, 26, '이에소드 메이스', 'Iesod Mace', 35872267, 6, 1, 0, 43000, 51, 76, 0, 1, 7, '(ADV,81)', 43000, 231, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (120, '이에소드 메이스 인페르노', 'Iesod Mace Inferno', 35872267, 6, 35, 25, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `MaceInfo` VALUES (26, 26, '메카닉 썬더 메이스', 'Mechanic Thunder Mace', 48427560, 6, 1, 0, 43000, 55, 82, 0, 1, 7, '(ADV,91)', 43000, 241, 16, 135, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (121, '메카닉 썬더 메이스 인페르노', 'Mechanic Thunder Mace Inferno', 48427560, 6, 35, 26, 100, '(ADV,91)', '', 0, 0);

-- CoatInfo Titanium Jacket W type 35 ADV 31 -> 91
UPDATE `CoatInfo` SET NextItemType=36 WHERE ItemType=35;
INSERT INTO `CoatInfo` VALUES (36, 37, '다이니마 케라틴 슈트 M', 'Dyneema Keratain Suit M', 8370000, 6, 6, 0, 45500, 162, 81, '(GEN,1)(ADV,41)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (122, '다이니마 케라틴 슈트 M 레전드리', 'Dyneema Keratain Suit M Legendry', 8370000, 6, 11, 36, 100, '(GEN,1)(ADV,41)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (37, 38, '다이니마 케라틴 슈트 W', 'Dyneema Keratain Suit W', 11299500, 6, 6, 0, 45500, 174, 87, '(GEN,2)(ADV,41)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (123, '다이니마 케라틴 슈트 W 레전드리', 'Dyneema Keratain Suit W Legendry', 11299500, 6, 11, 37, 100, '(GEN,2)(ADV,41)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (38, 39, '메테리얼 컴뱃 슈트 M', 'Material Combat Suit M', 15254325, 6, 6, 0, 45500, 188, 94, '(GEN,1)(ADV,51)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (124, '메테리얼 컴뱃 슈트 M 레전드리', 'Material Combat Suit M Legendry', 15254325, 6, 11, 38, 100, '(GEN,1)(ADV,51)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (39, 40, '메테리얼 컴뱃 슈트 W', 'Material Combat Suit W', 20593338, 6, 6, 0, 45500, 204, 102, '(GEN,2)(ADV,51)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (125, '메테리얼 컴뱃 슈트 W 레전드리', 'Material Combat Suit W Legendry', 20593338, 6, 11, 39, 100, '(GEN,2)(ADV,51)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (40, 41, '그리드 폴리머 나노 슈트 M', 'Greed Polymer Nano Suit M', 27801006, 6, 6, 0, 45500, 220, 110, '(GEN,1)(ADV,61)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (126, '그리드 폴리머 나노 슈트 M 레전드리', 'Greed Polymer Nano Suit M Legendry', 27801006, 6, 11, 40, 100, '(GEN,1)(ADV,61)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (41, 42, '그리드 폴리머 나노 슈트 W', 'Greed Polymer Nano Suit W', 37531358, 6, 6, 0, 45500, 238, 119, '(GEN,2)(ADV,61)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (127, '그리드 폴리머 나노 슈트 W 레전드리', 'Greed Polymer Nano Suit W Legendry', 37531358, 6, 11, 41, 100, '(GEN,2)(ADV,61)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (42, 43, '디펜시브 엘리먼트 코트 M', 'Defensive Element Coat M', 50667333, 6, 6, 0, 45500, 257, 128, '(GEN,1)(ADV,71)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (128, '디펜시브 엘리먼트 코트 M 레전드리', 'Defensive Element Coat M Legendry', 50667333, 6, 11, 42, 100, '(GEN,1)(ADV,71)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (43, 44, '디펜시브 엘리먼트 코트 W', 'Defensive Element Coat W', 68400899, 6, 6, 0, 45500, 277, 138, '(GEN,2)(ADV,71)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (129, '디펜시브 엘리먼트 코트 W 레전드리', 'Defensive Element Coat W Legendry', 68400899, 6, 11, 43, 100, '(GEN,2)(ADV,71)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (44, 45, '유물 : 고대의 배틀 아머 M', 'Ancient Battle Armor M', 92341213, 6, 6, 0, 45500, 299, 149, '(GEN,1)(ADV,81)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (130, '유물 : 고대의 배틀 아머 M 레전드리', 'Ancient Battle Armor M Legendry', 92341213, 6, 11, 44, 100, '(GEN,1)(ADV,81)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (45, 46, '유물 : 고대의 배틀 아머 W', 'Ancient Battle Armor W', 124660637, 6, 6, 0, 45500, 323, 161, '(GEN,2)(ADV,81)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (131, '유물 : 고대의 배틀 아머 W 레전드리', 'Ancient Battle Armor W Legendry', 124660637, 6, 11, 45, 100, '(GEN,2)(ADV,81)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (46, 47, '로바인 캄프 슈트 M', 'Lovine Kampf Suit M', 168291859, 6, 6, 0, 45500, 349, 174, '(GEN,1)(ADV,91)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (132, '로바인 캄프 슈트 M 레전드리', 'Lovine Kampf Suit M Legendry', 168291859, 6, 11, 46, 100, '(GEN,1)(ADV,91)', '', 0, 0);
INSERT INTO `CoatInfo` VALUES (47, 47, 'Lovine Kampf Suit W', 'Lovine Kampf Suit W', 227194009, 6, 6, 0, 45500, 377, 188, '(GEN,2)(ADV,91)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (133, 'Lovine Kampf Suit W 레전드리', 'Lovine Kampf Suit W Legendry', 227194009, 6, 11, 47, 100, '(GEN,2)(ADV,91)', '', 0, 0);

-- TrouserInfo Titanium Leggings W type 35 ADV 31 -> 91
UPDATE `TrouserInfo` SET NextItemType=36 WHERE ItemType=35;
INSERT INTO `TrouserInfo` VALUES (36, 37, '다이니마 케라틴 게이터 M', 'Dyneema Keratain Gaiter M', 11610000, 6, 6, 0, 38000, 129, 64, '(GEN,1)(ADV,41)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (134, '다이니마 케라틴 게이터 M 레전드리', 'Dyneema Keratain Gaiter M Legendry', 11610000, 6, 12, 36, 100, '(GEN,1)(ADV,41)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (37, 38, '다이니마 케라틴 게이터 W', 'Dyneema Keratain Gaiter W', 15673500, 6, 6, 0, 38000, 139, 69, '(GEN,2)(ADV,41)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (135, '다이니마 케라틴 게이터 W 레전드리', 'Dyneema Keratain Gaiter W Legendry', 15673500, 6, 12, 37, 100, '(GEN,2)(ADV,41)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (38, 39, '메테리얼 컴뱃 게이터 M', 'Material Combat Gaiters M', 21159225, 6, 6, 0, 38000, 151, 75, '(GEN,1)(ADV,51)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (136, '메테리얼 컴뱃 게이터 M 레전드리', 'Material Combat Gaiters M Legendry', 21159225, 6, 12, 38, 100, '(GEN,1)(ADV,51)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (39, 40, '메테리얼 컴뱃 게이터 W', 'Material Combat Gaiters W', 28564953, 6, 6, 0, 38000, 163, 81, '(GEN,2)(ADV,51)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (137, '메테리얼 컴뱃 게이터 W 레전드리', 'Material Combat Gaiters W Legendry', 28564953, 6, 12, 39, 100, '(GEN,2)(ADV,51)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (40, 41, '디펜시브 엘리먼트 슬랙 M', 'Defensive Element Slacks M', 38562686, 6, 6, 0, 38000, 176, 88, '(GEN,1)(ADV,61)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (138, '디펜시브 엘리먼트 슬랙 M 레전드리', 'Defensive Element Slacks M Legendry', 38562686, 6, 12, 40, 100, '(GEN,1)(ADV,61)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (41, 42, '디펜시브 엘리먼트 슬랙 W', 'Defensive Element Slacks W', 52059626, 6, 6, 0, 38000, 190, 95, '(GEN,2)(ADV,61)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (139, '디펜시브 엘리먼트 슬랙 W 레전드리', 'Defensive Element Slacks W Legendry', 52059626, 6, 12, 41, 100, '(GEN,2)(ADV,61)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (42, 43, '유물 : 고대의 배틀 가드 M', 'Ancient Battle Guard M', 70280495, 6, 6, 0, 38000, 205, 102, '(GEN,1)(ADV,71)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (140, '유물 : 고대의 배틀 가드 M 레전드리', 'Ancient Battle Guard M Legendry', 70280495, 6, 12, 42, 100, '(GEN,1)(ADV,71)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (43, 44, '유물 : 고대의 배틀 가드 W', 'Ancient Battle Guard W', 94878668, 6, 6, 0, 38000, 222, 111, '(GEN,2)(ADV,71)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (141, '유물 : 고대의 배틀 가드 W 레전드리', 'Ancient Battle Guard W Legendry', 94878668, 6, 12, 43, 100, '(GEN,2)(ADV,71)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (44, 45, '로바인 캄프 슬랙 M', 'Lovine Kampf Slacks M', 128086201, 6, 6, 0, 38000, 239, 119, '(GEN,1)(ADV,91)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (142, '로바인 캄프 슬랙 M 레전드리', 'Lovine Kampf Slacks M Legendry', 128086201, 6, 12, 44, 100, '(GEN,1)(ADV,91)', '', 0, 0);
INSERT INTO `TrouserInfo` VALUES (45, 45, 'Lovine Kampf Slacks W', 'Lovine Kampf Slacks W', 172916371, 6, 6, 0, 38000, 259, 129, '(GEN,2)(ADV,91)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (143, 'Lovine Kampf Slacks W 레전드리', 'Lovine Kampf Slacks W Legendry', 172916371, 6, 12, 45, 100, '(GEN,2)(ADV,91)', '', 0, 0);

-- HelmInfo Cyclops Fluoroscope type 17 ADV 31 -> 91
UPDATE `HelmInfo` SET NextItemType=18 WHERE ItemType=17;
INSERT INTO `HelmInfo` VALUES (18, 19, 'HUD 헤드업 고글', 'HUD Headup Goggles', 10395000, 5, 15, 0, 17400, 49, 35, '(ADV,41)', 15, '', 0, 30, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (144, 'HUD 헤드업 고글 레전드리', 'HUD Headup Goggles Legendry', 10395000, 6, 13, 18, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `HelmInfo` VALUES (19, 20, '메테리얼 컴뱃 헬멧', 'Material Combat Helmet', 14033250, 5, 15, 0, 17400, 53, 38, '(ADV,51)', 15, '', 0, 30, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (145, '메테리얼 컴뱃 헬멧 레전드리', 'Material Combat Helmet Legendry', 14033250, 6, 13, 19, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `HelmInfo` VALUES (20, 21, '디펜시브 엘리먼트 헬멧', 'Defensive Element Helmet', 18944887, 5, 15, 0, 17400, 57, 41, '(ADV,61)', 15, '', 0, 30, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (146, '디펜시브 엘리먼트 헬멧 레전드리', 'Defensive Element Helmet Legendry', 18944887, 6, 13, 20, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `HelmInfo` VALUES (21, 22, '유물 : 고대의 헬멧', 'Ancient Helm', 25575597, 5, 15, 0, 17400, 62, 44, '(ADV,71)', 15, '', 0, 30, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (147, '유물 : 고대의 헬멧 레전드리', 'Ancient Helm Legendry', 25575597, 6, 13, 21, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `HelmInfo` VALUES (22, 22, '로바인 캄프 고글', 'Lovine Kampf Goggles', 34527055, 5, 15, 0, 17400, 67, 48, '(ADV,91)', 15, '', 0, 30, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (148, '로바인 캄프 고글 레전드리', 'Lovine Kampf Goggles Legendry', 34527055, 6, 13, 22, 100, '(ADV,91)', '', 0, 0);

-- ShieldInfo Buffalo Sheild type 17 ADV 31 -> 91
UPDATE `ShieldInfo` SET NextItemType=18 WHERE ItemType=17;
INSERT INTO `ShieldInfo` VALUES (18, 19, '임페니트레블 베리어', 'Impenitrable Barrier', 10395000, 6, 15, 0, 22400, 68, 32, '(ADV,41)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (149, '임페니트레블 베리어 레전드리', 'Impenitrable Barrier Legendry', 10395000, 6, 16, 18, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `ShieldInfo` VALUES (19, 20, '메테리얼 컴뱃 쉴드', 'Material Combat Sheild', 14033250, 6, 15, 0, 22400, 73, 34, '(ADV,51)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (150, '메테리얼 컴뱃 쉴드 레전드리', 'Material Combat Sheild Legendry', 14033250, 6, 16, 19, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `ShieldInfo` VALUES (20, 21, '디펜시브 엘리먼트 쉴드', 'Defensive Element Shield', 18944887, 6, 15, 0, 22400, 79, 37, '(ADV,61)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (151, '디펜시브 엘리먼트 쉴드 레전드리', 'Defensive Element Shield Legendry', 18944887, 6, 16, 20, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `ShieldInfo` VALUES (21, 22, '유물 : 고대의 쉴드', 'Ancient Shield', 25575597, 6, 15, 0, 22400, 85, 40, '(ADV,71)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (152, '유물 : 고대의 쉴드 레전드리', 'Ancient Shield Legendry', 25575597, 6, 16, 21, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `ShieldInfo` VALUES (22, 22, '로바인 캄프 쉴드', 'Lovine Kampf Shield', 34527055, 6, 15, 0, 22400, 92, 44, '(ADV,91)', 15, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (153, '로바인 캄프 쉴드 레전드리', 'Lovine Kampf Shield Legendry', 34527055, 6, 16, 22, 100, '(ADV,91)', '', 0, 0);

-- GloveInfo Leopard Guntlet type 14 ADV 11 -> 91
UPDATE `GloveInfo` SET NextItemType=15 WHERE ItemType=14;
INSERT INTO `GloveInfo` VALUES (15, 16, '세라믹 나노 실버 건틀렛', 'Ceramic Nano Silver Guntlet', 8100000, 5, 5, 0, 6800, 30, 15, '(ADV,21)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (154, '세라믹 나노 실버 건틀렛 레전드리', 'Ceramic Nano Silver Guntlet Legendry', 8100000, 6, 18, 15, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `GloveInfo` VALUES (16, 17, '에어 센서 가드', 'Air Sensor Guard', 10935000, 5, 5, 0, 6800, 32, 16, '(ADV,31)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (155, '에어 센서 가드 레전드리', 'Air Sensor Guard Legendry', 10935000, 6, 18, 16, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `GloveInfo` VALUES (17, 18, '싸이클 글러브', 'Cycle Glove', 14762250, 5, 5, 0, 6800, 35, 17, '(ADV,41)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (156, '싸이클 글러브 레전드리', 'Cycle Glove Legendry', 14762250, 6, 18, 17, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `GloveInfo` VALUES (18, 18, '로바인 캄프 글러브', 'Lovine Kampf Glove', 19929037, 5, 5, 0, 6800, 38, 19, '(ADV,91)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (157, '로바인 캄프 글러브 레전드리', 'Lovine Kampf Glove Legendry', 19929037, 6, 18, 18, 100, '(ADV,91)', '', 0, 0);

-- ShoesInfo Ceres Bootscut type 13 ADV 11 -> 91
UPDATE `ShoesInfo` SET NextItemType=14 WHERE ItemType=13;
INSERT INTO `ShoesInfo` VALUES (14, 15, '케블라 카브웹 슈즈', 'Kevlar Cobweb Shoes', 8100000, 5, 3, 5, 5500, 32, 21, '(ADV,21)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (158, '케블라 카브웹 슈즈 레전드리', 'Kevlar Cobweb Shoes Legendry', 8100000, 6, 19, 14, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `ShoesInfo` VALUES (15, 16, '실버 플레이트 프로텍터', 'Silver Plate Protector', 10935000, 5, 3, 5, 5500, 34, 23, '(ADV,31)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (159, '실버 플레이트 프로텍터 레전드리', 'Silver Plate Protector Legendry', 10935000, 6, 19, 15, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `ShoesInfo` VALUES (16, 17, '코볼트 부츠', 'Kobolt Boots', 14762250, 5, 3, 5, 5500, 37, 25, '(ADV,41)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (160, '코볼트 부츠 레전드리', 'Kobolt Boots Legendry', 14762250, 6, 19, 16, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `ShoesInfo` VALUES (17, 17, '로바인 캄프 부츠', 'Lovine Kampf Boots', 19929037, 5, 3, 5, 5500, 40, 27, '(ADV,91)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (161, '로바인 캄프 부츠 레전드리', 'Lovine Kampf Boots Legendry', 19929037, 6, 19, 17, 100, '(ADV,91)', '', 0, 0);

-- BeltInfo Diana Leather Belt type 11 ADV 11 -> 91
UPDATE `BeltInfo` SET NextItemType=12 WHERE ItemType=11;
INSERT INTO `BeltInfo` VALUES (12, 13, '듀얼 숄더 벨트', 'Dual Shoulder Belt', 8100000, 5, 6, 0, 10800, 18, 11, 8, '(ADV,21)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (162, '듀얼 숄더 벨트 레전드리', 'Dual Shoulder Belt Legendry', 8100000, 6, 26, 12, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `BeltInfo` VALUES (13, 14, 'CHAS 프로텍트 버클', 'CHAS Protect Buckle', 10935000, 5, 6, 0, 10800, 19, 12, 8, '(ADV,31)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (163, 'CHAS 프로텍트 버클 레전드리', 'CHAS Protect Buckle Legendry', 10935000, 6, 26, 13, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `BeltInfo` VALUES (14, 15, 'S 컴뱃 레그 벨트', 'S Combat Leg Belt', 14762250, 5, 6, 0, 10800, 21, 13, 8, '(ADV,41)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (164, 'S 컴뱃 레그 벨트 레전드리', 'S Combat Leg Belt Legendry', 14762250, 6, 26, 14, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `BeltInfo` VALUES (15, 16, '다이니마 숄더 홀스터', 'Dyneema Shoulder Holster', 19929037, 5, 6, 0, 10800, 23, 14, 8, '(ADV,51)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (165, '다이니마 숄더 홀스터 레전드리', 'Dyneema Shoulder Holster Legendry', 19929037, 6, 26, 15, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `BeltInfo` VALUES (16, 17, '메테리얼 컴뱃 버클', 'Material Combat Buckle', 26904199, 5, 6, 0, 10800, 24, 16, 8, '(ADV,61)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (166, '메테리얼 컴뱃 버클 레전드리', 'Material Combat Buckle Legendry', 26904199, 6, 26, 16, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `BeltInfo` VALUES (17, 18, '디펜시브 엘리먼트 벨트', 'Defensive Element Belt', 36320668, 5, 6, 0, 10800, 26, 17, 8, '(ADV,71)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (167, '디펜시브 엘리먼트 벨트 레전드리', 'Defensive Element Belt Legendry', 36320668, 6, 26, 17, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `BeltInfo` VALUES (18, 18, '유물 : 고대의 워 벨트', 'Ancient War Belt', 49032901, 5, 6, 0, 10800, 29, 18, 8, '(ADV,91)', 13, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (168, '유물 : 고대의 워 벨트 레전드리', 'Ancient War Belt Legendry', 49032901, 6, 26, 18, 100, '(ADV,91)', '', 0, 0);

-- RingInfo Holy Ring of Raphael type 19 ADV 21 -> 91
UPDATE `RingInfo` SET NextItemType=20 WHERE ItemType=19;
INSERT INTO `RingInfo` VALUES (20, 21, 'Harpy', 'Harpy', 1349998, 1, 2, 0, 25000, 30, 18, '(ADV,31)', 255, 'INT+9,HP+6,PRO+9', 0, 0, 0, 0, 1, 11);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (169, 'Harpy 아티클', 'Harpy Article', 4000000, 6, 8, 20, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `RingInfo` VALUES (21, 21, '플래티넘 스파이럴', 'Platinum Spiral', 1822497, 1, 2, 0, 25000, 32, 19, '(ADV,91)', 255, 'INT+9,HP+6,PRO+9', 0, 0, 0, 0, 1, 11);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (170, '플래티넘 스파이럴 아티클', 'Platinum Spiral Article', 4000000, 6, 8, 21, 100, '(ADV,91)', '', 0, 0);

-- NecklaceInfo Reliquary of Vatican type 18 ADV 21 -> 91
UPDATE `NecklaceInfo` SET NextItemType=19 WHERE ItemType=18;
INSERT INTO `NecklaceInfo` VALUES (19, 20, 'Ariel', 'Ariel', 1349998, 1, 1, 0, 25000, 20, 18, '(ADV,31)', 255, 'TOHIT+10,DEX+10,HPSTL+6', 0, 0, 0, 0, 1, 12);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (171, 'Ariel 아티클', 'Ariel Article', 4000000, 6, 9, 19, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `NecklaceInfo` VALUES (20, 20, 'Blue Marine', 'Blue Marine', 1822497, 1, 1, 0, 25000, 22, 19, '(ADV,91)', 255, 'TOHIT+10,DEX+10,HPSTL+6', 0, 0, 0, 0, 1, 12);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (172, 'Blue Marine 아티클', 'Blue Marine Article', 4000000, 6, 9, 20, 100, '(ADV,91)', '', 0, 0);

-- BraceletInfo Eternal Bracelet type 18 ADV 21 -> 91
UPDATE `BraceletInfo` SET NextItemType=19 WHERE ItemType=18;
INSERT INTO `BraceletInfo` VALUES (19, 20, 'Gold Spider', 'Gold Spider', 3375000, 1, 1, 0, 33000, 23, 11, '(ADV,31)', 15, '', 0, 0, 0, 0, 1, 7);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (173, 'Gold Spider 아티클', 'Gold Spider Article', 4000000, 6, 10, 19, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `BraceletInfo` VALUES (20, 20, 'Dionys', 'Dionys', 4556250, 1, 1, 0, 33000, 25, 12, '(ADV,91)', 15, '', 0, 0, 0, 0, 1, 7);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (174, 'Dionys 아티클', 'Dionys Article', 4556250, 6, 10, 20, 100, '(ADV,91)', '', 0, 0);

-- VampireWeaponInfo Claw Of Valakas type 27 ADV 31 -> 91
INSERT INTO `VampireWeaponInfo` VALUES (28, 'Cursed Claw', 'Cursed Claw', 10800000, 5, 1, 0, 65000, 32, 42, 59, 1, 11, '(ADV,91)', 21, 241, '', 0, 0, 0, 28, 0, 2);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (46, 'Cursed Claw 인페르노', 'Cursed Claw Inferno', 10800000, 6, 44, 28, 100, '(ADV,91)', '', 0, 0);

-- VampireCoatInfo Proud Appare-51 W type 35 ADV 51 -> 91
INSERT INTO `VampireCoatInfo` VALUES (36, '트와일라잇 블랙 코트', 'Twilight Black Coat', 5400000, 6, 6, 0, 65535, 245, 210, '(ADV,61)', 16, '', 80, 135, 210, 35, 135, 2);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (47, '트와일라잇 블랙 코트 레전드리', 'Twilight Black Coat Legendry', 5400000, 6, 33, 36, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `VampireCoatInfo` VALUES (37, '트와일라잇 블랙 드레스', 'Twilight Black Dress', 7290000, 6, 6, 0, 65535, 245, 227, '(ADV,91)', 16, '', 80, 135, 210, 35, 135, 2);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (48, '트와일라잇 블랙 드레스 레전드리', 'Twilight Black Dress Legendry', 7290000, 6, 33, 37, 100, '(ADV,91)', '', 0, 0);

-- VampireEarringInfo The Snake Eye type 18 ADV 21 -> 91
INSERT INTO `VampireEarringInfo` VALUES (19, '게이지 이어링', 'Gauge Earring', 3375000, 1, 3, 0, 33000, 23, 21, '(ADV,31)', 15, '', 0, 0, 0, 19, 0, 2, 5);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (49, '게이지 이어링 아티클', 'Gauge Earring Article', 4000000, 6, 30, 19, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `VampireEarringInfo` VALUES (20, 'Cursed Rose Earring', 'Cursed Rose Earring', 4556250, 1, 3, 0, 33000, 23, 23, '(ADV,91)', 15, '', 0, 0, 0, 19, 0, 2, 5);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (50, 'Cursed Rose Earring 아티클', 'Cursed Rose Earring Article', 4556250, 6, 30, 20, 100, '(ADV,91)', '', 0, 0);

-- VampireNecklaceInfo Amethyst Serpent type 18 ADV 21 -> 91
INSERT INTO `VampireNecklaceInfo` VALUES (19, '오피디아시스', 'Ophidiasis', 1349998, 1, 1, 24000, 33, 22, '(ADV,31)', 0, 181, 'RES+6,ATTR+4,DEF+5', 0, 0, 0, 18, 0, 2, 10);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (51, '오피디아시스 아티클', 'Ophidiasis Article', 4000000, 6, 32, 19, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `VampireNecklaceInfo` VALUES (20, '커즈 블랙로즈 네크리스', 'Cursed BlackRose Necklace', 1822497, 1, 1, 24000, 33, 22, '(ADV,91)', 0, 241, 'RES+6,ATTR+4,DEF+5', 0, 0, 0, 18, 0, 2, 10);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (52, '커즈 블랙로즈 네크리스 아티클', 'Cursed BlackRose Necklace Article', 4000000, 6, 32, 20, 100, '(ADV,91)', '', 0, 0);

-- VampireBraceletInfo Baska Bracelet type 15 ADV 11 -> 91
INSERT INTO `VampireBraceletInfo` VALUES (16, '트레쥬리 브레이슬릿', 'Treasury Bracelet', 2700000, 1, 1, 1, 35000, 20, 12, '(ADV,21)', 14, '', 0, 30, 1, 17, 0, 2, 4);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (53, '트레쥬리 브레이슬릿 아티클', 'Treasury Bracelet Article', 4000000, 6, 31, 16, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `VampireBraceletInfo` VALUES (17, '커즈 바이퍼 브레이슬릿', 'Cursed Viper Bracelet', 3645000, 1, 1, 1, 35000, 20, 13, '(ADV,91)', 14, '', 0, 30, 1, 17, 0, 2, 4);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (54, '커즈 바이퍼 브레이슬릿 아티클', 'Cursed Viper Bracelet Article', 4000000, 6, 31, 17, 100, '(ADV,91)', '', 0, 0);

-- VampireRingInfo Pledge in Blood type 19 ADV 21 -> 91
INSERT INTO `VampireRingInfo` VALUES (20, '트윅스 코일러', 'Twix Coiler', 1349998, 1, 1, 0, 24000, 32, 23, '(ADV,31)', 255, 'BLRES+5,ASPD+4,DEF+4', 0, 0, 0, 19, 0, 2, 10);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (55, '트윅스 코일러 아티클', 'Twix Coiler Article', 4000000, 6, 42, 20, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `VampireRingInfo` VALUES (21, '커즈 블러드 링', 'Cursed Blood Ring', 1822497, 1, 1, 0, 24000, 32, 25, '(ADV,91)', 255, 'BLRES+5,ASPD+4,DEF+4', 0, 0, 0, 19, 0, 2, 10);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (56, '커즈 블러드 링 아티클', 'Cursed Blood Ring Article', 4000000, 6, 42, 21, 100, '(ADV,91)', '', 0, 0);

-- VampireAmuletInfo Impeller type 17 ADV 11 -> 91
INSERT INTO `VampireAmuletInfo` VALUES (18, '아이드', 'Eyed', 2700000, 1, 3, 0, 30000, 13, 10, '(ADV,21)', 14, '', 10, 10, 1, 18, 40, 2, 3);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (57, '아이드 아티클', 'Eyed Article', 4000000, 6, 45, 18, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `VampireAmuletInfo` VALUES (19, 'Cursed Tears Bead', 'Cursed Tears Bead', 3645000, 1, 3, 0, 30000, 13, 11, '(ADV,91)', 14, '', 10, 10, 1, 18, 40, 2, 3);
INSERT INTO `VampireTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (58, 'Cursed Tears Bead 아티클', 'Cursed Tears Bead Article', 4000000, 6, 45, 19, 100, '(ADV,91)', '', 0, 0);

-- OustersChakramInfo Chakram Of Tyrfingr type 22 ADV 31 -> 91
INSERT INTO `OustersChakramInfo` VALUES (23, '샤프 블래스트 차크람', 'Sharp Blast Chakram', 8100000, 6, 1, 0, 53000, 44, 65, 59, 1, 7, '(ADV,41)', 16, 191, '', 0, 0, 0, 23, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (48, '샤프 블래스트 차크람 인페르노', 'Sharp Blast Chakram Inferno', 8100000, 6, 59, 23, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersChakramInfo` VALUES (24, '리스트레인 엔젤 챠크람', 'Restrain Angel Chakram', 10935000, 6, 1, 0, 53000, 44, 71, 64, 1, 7, '(ADV,51)', 16, 201, '', 0, 0, 0, 23, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (49, '리스트레인 엔젤 챠크람 인페르노', 'Restrain Angel Chakram Inferno', 10935000, 6, 59, 24, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `OustersChakramInfo` VALUES (25, '트리니티 서클 챠크람', 'Trinity Circle Charkram', 14762250, 6, 1, 0, 53000, 44, 76, 69, 1, 7, '(ADV,61)', 16, 211, '', 0, 0, 0, 23, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (50, '트리니티 서클 챠크람 인페르노', 'Trinity Circle Charkram Inferno', 14762250, 6, 59, 25, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `OustersChakramInfo` VALUES (26, '블루밍 페탈 차크람', 'Blooming Petal Chakram', 19929037, 6, 1, 0, 53000, 44, 82, 74, 1, 7, '(ADV,71)', 16, 221, '', 0, 0, 0, 23, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (51, '블루밍 페탈 차크람 인페르노', 'Blooming Petal Chakram Inferno', 19929037, 6, 59, 26, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `OustersChakramInfo` VALUES (27, '코쿠마 차크람', 'Cochma Chakram', 26904199, 6, 1, 0, 53000, 44, 89, 80, 1, 7, '(ADV,81)', 16, 231, '', 0, 0, 0, 23, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (52, '코쿠마 차크람 인페르노', 'Cochma Chakram Inferno', 26904199, 6, 59, 27, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `OustersChakramInfo` VALUES (28, 'Iris Chakram', 'Iris Chakram', 36320668, 6, 1, 0, 53000, 44, 96, 87, 1, 7, '(ADV,91)', 16, 241, '', 0, 0, 0, 23, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (53, 'Iris Chakram 인페르노', 'Iris Chakram Inferno', 36320668, 6, 59, 28, 100, '(ADV,91)', '', 0, 0);

-- OustersWristletInfo Wristlet Of Indra type 68 ADV 31 -> 91
INSERT INTO `OustersWristletInfo` VALUES (69, '이그니스 가디언 리스틀릿', 'Ignis Guardian Wristlet', 10800000, 6, 1, 0, 43000, 31, 49, 0, 9, 0, '(ADV,41)', 16, 191, '', 0, 0, 0, 71, 0, 2, 5, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (54, '이그니스 가디언 리스틀릿 인페르노', 'Ignis Guardian Wristlet Inferno', 10800000, 6, 65, 69, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersWristletInfo` VALUES (70, '아에로 리스틀릿 [불]', 'Aello Wristlet [Fire]', 14580000, 6, 1, 0, 43000, 31, 53, 0, 9, 0, '(ADV,91)', 16, 241, '', 0, 0, 0, 71, 0, 2, 5, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (55, '아에로 리스틀릿 [불] 인페르노', 'Aello Wristlet [Fire] Inferno', 14580000, 6, 65, 70, 100, '(ADV,91)', '', 0, 0);

-- OustersCoatInfo Crown Coat type 17 ADV 31 -> 91
INSERT INTO `OustersCoatInfo` VALUES (18, '세린 에올리언 코트', 'Serene Aeolian Coat', 12825000, 6, 6, 0, 37500, 156, 86, '(ADV,41)', 16, '', 0, 0, 0, 18, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (56, '세린 에올리언 코트 레전드리', 'Serene Aeolian Coat Legendry', 12825000, 6, 61, 18, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersCoatInfo` VALUES (19, '리스트레인 인타이스 코트', 'Restrain Entice Coat', 17313750, 6, 6, 0, 37500, 156, 93, '(ADV,51)', 16, '', 0, 0, 0, 18, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (57, '리스트레인 인타이스 코트 레전드리', 'Restrain Entice Coat Legendry', 17313750, 6, 61, 19, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `OustersCoatInfo` VALUES (20, '트리니티 제네시스 코트', 'Trinity Jenesis Coat', 23373562, 6, 6, 0, 37500, 156, 100, '(ADV,61)', 16, '', 0, 0, 0, 18, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (58, '트리니티 제네시스 코트 레전드리', 'Trinity Jenesis Coat Legendry', 23373562, 6, 61, 20, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `OustersCoatInfo` VALUES (21, '블루밍 포스 코트', 'Blooming Force Coat', 31554308, 6, 6, 0, 37500, 156, 108, '(ADV,71)', 16, '', 0, 0, 0, 18, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (59, '블루밍 포스 코트 레전드리', 'Blooming Force Coat Legendry', 31554308, 6, 61, 21, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `OustersCoatInfo` VALUES (22, '유물 : 고대 정령의 코트', 'Ancient Elemental Coat', 42598315, 6, 6, 0, 37500, 156, 117, '(ADV,81)', 16, '', 0, 0, 0, 18, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (60, '유물 : 고대 정령의 코트 레전드리', 'Ancient Elemental Coat Legendry', 42598315, 6, 61, 22, 100, '(ADV,81)', '', 0, 0);
INSERT INTO `OustersCoatInfo` VALUES (23, 'Regina Silk Dress', 'Regina Silk Dress', 57507725, 6, 6, 0, 37500, 156, 126, '(ADV,91)', 16, '', 0, 0, 0, 18, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (61, 'Regina Silk Dress 레전드리', 'Regina Silk Dress Legendry', 57507725, 6, 61, 23, 100, '(ADV,91)', '', 0, 0);

-- OustersBootsInfo Arkadhia Tublar type 17 ADV 31 -> 91
UPDATE `OustersBootsInfo` SET NextItemType=18 WHERE ItemType=17;
INSERT INTO `OustersBootsInfo` VALUES (18, 19, '세린 에올리언 부츠', 'Serene Aeolian Boots', 12825000, 6, 6, 0, 35750, 109, 82, '(ADV,41)', 16, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (62, '세린 에올리언 부츠 레전드리', 'Serene Aeolian Boots Legendry', 12825000, 6, 58, 18, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersBootsInfo` VALUES (19, 20, '리스트레인 소울 부츠', 'Restrain Soul Boots', 17313750, 6, 6, 0, 35750, 117, 88, '(ADV,51)', 16, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (63, '리스트레인 소울 부츠 레전드리', 'Restrain Soul Boots Legendry', 17313750, 6, 58, 19, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `OustersBootsInfo` VALUES (20, 21, '블루밍 포스 부츠', 'Blooming Force Boots', 23373562, 6, 6, 0, 35750, 127, 95, '(ADV,61)', 16, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (64, '블루밍 포스 부츠 레전드리', 'Blooming Force Boots Legendry', 23373562, 6, 58, 20, 100, '(ADV,61)', '', 0, 0);
INSERT INTO `OustersBootsInfo` VALUES (21, 22, '유물 : 고대 정령의 부츠', 'Ancient Elemental Boots', 31554308, 6, 6, 0, 35750, 137, 103, '(ADV,71)', 16, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (65, '유물 : 고대 정령의 부츠 레전드리', 'Ancient Elemental Boots Legendry', 31554308, 6, 58, 21, 100, '(ADV,71)', '', 0, 0);
INSERT INTO `OustersBootsInfo` VALUES (22, 22, 'Regina Cristal Heel', 'Regina Cristal Heel', 42598315, 6, 6, 0, 35750, 148, 111, '(ADV,91)', 16, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (66, 'Regina Cristal Heel 레전드리', 'Regina Cristal Heel Legendry', 42598315, 6, 58, 22, 100, '(ADV,91)', '', 0, 0);

-- OustersCircletInfo Royal Circlet type 16 ADV 11 -> 91
UPDATE `OustersCircletInfo` SET NextItemType=17 WHERE ItemType=16;
INSERT INTO `OustersCircletInfo` VALUES (17, 18, '아이드롭 다이아 서클릿', 'Eyedrop Dia Circlet', 8100000, 5, 2, 0, 11000, 58, 31, '(ADV,21)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (67, '아이드롭 다이아 서클릿 레전드리', 'Eyedrop Dia Circlet Legendry', 8100000, 6, 60, 17, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `OustersCircletInfo` VALUES (18, 19, '앤티세스 서클릿', 'Anthesis Circlet', 10935000, 5, 2, 0, 11000, 62, 33, '(ADV,31)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (68, '앤티세스 서클릿 레전드리', 'Anthesis Circlet Legendry', 10935000, 6, 60, 18, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `OustersCircletInfo` VALUES (19, 20, '쏜버시 서클릿', 'Thornbush Circlet', 14762250, 5, 2, 0, 11000, 68, 36, '(ADV,41)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (69, '쏜버시 서클릿 레전드리', 'Thornbush Circlet Legendry', 14762250, 6, 60, 19, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersCircletInfo` VALUES (20, 20, 'Regina Ruby Circlet', 'Regina Ruby Circlet', 19929037, 5, 2, 0, 11000, 73, 39, '(ADV,91)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (70, 'Regina Ruby Circlet 레전드리', 'Regina Ruby Circlet Legendry', 19929037, 6, 60, 20, 100, '(ADV,91)', '', 0, 0);

-- OustersArmsbandInfo Side Arms Grinder type 17 ADV 11 -> 91
UPDATE `OustersArmsbandInfo` SET NextItemType=18 WHERE ItemType=17;
INSERT INTO `OustersArmsbandInfo` VALUES (18, 19, '헬릭스 암즈 스트랩', 'Helix Arms Strap', 8100000, 5, 2, 0, 21000, 44, 17, 3, '(ADV,21)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (71, '헬릭스 암즈 스트랩 레전드리', 'Helix Arms Strap Legendry', 8100000, 6, 57, 18, 100, '(ADV,21)', '', 0, 0);
INSERT INTO `OustersArmsbandInfo` VALUES (19, 20, '리스트레이너 암스밴드', 'Restrainer Armsband', 10935000, 5, 2, 0, 21000, 47, 18, 3, '(ADV,31)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (72, '리스트레이너 암스밴드 레전드리', 'Restrainer Armsband Legendry', 10935000, 6, 57, 19, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `OustersArmsbandInfo` VALUES (20, 21, '플로라 암스밴드', 'Flora Armsband', 14762250, 5, 2, 0, 21000, 51, 20, 3, '(ADV,41)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (73, '플로라 암스밴드 레전드리', 'Flora Armsband Legendry', 14762250, 6, 57, 20, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersArmsbandInfo` VALUES (21, 21, 'Regina Blue Armsband', 'Regina Blue Armsband', 19929037, 5, 2, 0, 21000, 55, 21, 3, '(ADV,91)', 14, '', 0, 0, 0, 0, 4);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (74, 'Regina Blue Armsband 레전드리', 'Regina Blue Armsband Legendry', 19929037, 6, 57, 21, 100, '(ADV,91)', '', 0, 0);

-- OustersPendentInfo Tear of Radchia type 18 ADV 21 -> 91
INSERT INTO `OustersPendentInfo` VALUES (19, '노블 시리우스', 'Noble Sirius', 1349998, 1, 3, 65535, 33, 23, '(ADV,31)', 0, 181, 'RES+6,DAM+5,TOHIT+6', 0, 0, 0, 18, 0, 4, 11);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (75, '노블 시리우스 아티클', 'Noble Sirius Article', 4000000, 6, 62, 19, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `OustersPendentInfo` VALUES (20, '셰클즈 오브 엔젤', 'Shackles of Angel', 1822497, 1, 3, 65535, 33, 23, '(ADV,41)', 0, 191, 'RES+6,DAM+5,TOHIT+6', 0, 0, 0, 18, 0, 4, 11);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (76, '셰클즈 오브 엔젤 아티클', 'Shackles of Angel Article', 4000000, 6, 62, 20, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersPendentInfo` VALUES (21, '닉시 펜던트?', 'Nixie Pendent', 2460370, 1, 3, 65535, 33, 23, '(ADV,51)', 0, 201, 'RES+6,DAM+5,TOHIT+6', 0, 0, 0, 18, 0, 4, 11);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (77, '닉시 펜던트? 아티클', 'Nixie Pendent Article', 4000000, 6, 62, 21, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `OustersPendentInfo` VALUES (22, 'Regina Emerald Pendent', 'Regina Emerald Pendent', 3321499, 1, 3, 65535, 33, 23, '(ADV,91)', 0, 241, 'RES+6,DAM+5,TOHIT+6', 0, 0, 0, 18, 0, 4, 11);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (78, 'Regina Emerald Pendent 아티클', 'Regina Emerald Pendent Article', 4000000, 6, 62, 22, 100, '(ADV,91)', '', 0, 0);

-- OustersRingInfo Ring of Carisase Soul type 19 ADV 21 -> 91
INSERT INTO `OustersRingInfo` VALUES (20, '펠루시드 주드 링', 'Pelucid Jude Ring', 1349998, 1, 3, 0, 65535, 27, 15, '(ADV,31)', 255, 'BLRES+5,ATTR+4,PRO+6', 0, 0, 0, 19, 0, 4, 10);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (79, '펠루시드 주드 링 아티클', 'Pelucid Jude Ring Article', 4000000, 6, 63, 20, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `OustersRingInfo` VALUES (21, '에수아트 소아르타', 'Esuat Soarta', 1822497, 1, 3, 0, 65535, 27, 16, '(ADV,41)', 255, 'BLRES+5,ATTR+4,PRO+6', 0, 0, 0, 19, 0, 4, 10);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (80, '에수아트 소아르타 아티클', 'Esuat Soarta Article', 4000000, 6, 63, 21, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersRingInfo` VALUES (22, '버스트 링', 'Burst Ring', 2460370, 1, 3, 0, 65535, 27, 17, '(ADV,51)', 255, 'BLRES+5,ATTR+4,PRO+6', 0, 0, 0, 19, 0, 4, 10);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (81, '버스트 링 아티클', 'Burst Ring Article', 4000000, 6, 63, 22, 100, '(ADV,51)', '', 0, 0);
INSERT INTO `OustersRingInfo` VALUES (23, 'Regina Diamond Ring', 'Regina Diamond Ring', 3321499, 1, 3, 0, 65535, 27, 19, '(ADV,91)', 255, 'BLRES+5,ATTR+4,PRO+6', 0, 0, 0, 19, 0, 4, 10);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (82, 'Regina Diamond Ring 아티클', 'Regina Diamond Ring Article', 4000000, 6, 63, 23, 100, '(ADV,91)', '', 0, 0);

-- OustersStoneInfo Terra ElementalStone 3 type 29 ADV 21 -> 91
INSERT INTO `OustersStoneInfo` VALUES (30, '파먼트 피아트라', 'Pamant Piatra', 337500, 1, 3, 2000, 26000, 14, 7, '(ADV,31)', 15, '', 50, 150, 18, 32, 64, 2, 5, 4, 5);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (83, '파먼트 피아트라 아티클', 'Pamant Piatra Article', 4000000, 6, 64, 30, 100, '(ADV,31)', '', 0, 0);
INSERT INTO `OustersStoneInfo` VALUES (31, '샐라임의 정령석', 'Salaime`s ElementalStone', 455625, 1, 3, 2000, 26000, 14, 8, '(ADV,41)', 15, '', 50, 150, 18, 32, 64, 2, 5, 4, 5);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (84, '샐라임의 정령석 아티클', 'Salaime`s ElementalStone Article', 4000000, 6, 64, 31, 100, '(ADV,41)', '', 0, 0);
INSERT INTO `OustersStoneInfo` VALUES (32, 'Harpy\'s Red Stone', 'Harpy\'s Red Stone', 615093, 1, 3, 2000, 26000, 14, 8, '(ADV,91)', 15, '', 50, 150, 18, 32, 64, 2, 5, 4, 5);
INSERT INTO `OustersTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (85, 'Harpy\'s Red Stone 아티클', 'Harpy\'s Red Stone Article', 4000000, 6, 64, 32, 100, '(ADV,91)', '', 0, 0);


-- Soul Cutter is the Ptah blade. See client files.

UPDATE `BladeInfo` SET NextItemType=28 WHERE ItemType=27;
INSERT INTO `BladeInfo` VALUES (28, 28, 'Soul Cutter', 'Soul Cutter', 35872267, 6, 1, 0, 63000, 86, 112, 55, 1, 5, '(ADV,91)', 63000, 241, 79, '', 0, 0, 0, 0, 1);
INSERT INTO `SlayerTunningItemInfo` (ItemType, Name, EName, Price, Volume, TunningItemClass, TunningItemType, Ratio, ReqAbility, OwnerID, Storage, OwnerCharID) VALUES (176, 'Soul Cutter Inferno', 'Soul Cutter Inferno', 35872267, 6, 15, 28, 100, '(ADV,91)', '', 0, 0);
