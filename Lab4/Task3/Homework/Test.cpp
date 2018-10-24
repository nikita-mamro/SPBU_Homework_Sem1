#include "Test.hpp"

void askForTests()
{
	printf("–í—ã —É–≤–µ—Ä–µ–Ω—ã, —á—Ç–æ —Ö–æ—Ç–∏—Ç–µ –ø—Ä–æ–≤–æ–¥–∏—Ç—å —Ç–µ—Å—Ç—ã?\n–û–Ω–∏ —Å—Ç–∏—Ä–∞—é—Ç –¥–∞–Ω–Ω—ã–µ –∏–∑ —Ñ–∞–π–ª–∞ —Å–ø—Ä–∞–≤–æ—á–Ω–∏–∫–∞, –µ—Å–ª–∏ —É –≤–∞—Å —Ç–∞–∫–æ–≤–æ–π –∏–º–µ–µ—Ç—Å—è.\n");
	srand(time(nullptr));
	int key = (rand() % 1000 + 1) * (rand() % 1000 + 1);
	int input = 0;
<<<<<<< HEAD
	printf("¬‚Â‰ËÚÂ ÍÎ˛˜ %d ‰Îˇ ÔÓ‰Ú‚ÂÊ‰ÂÌËˇ Ì‡˜‡Î‡ ÚÂÒÚÓ‚ ‰Îˇ ÚÂÒÚËÓ‚‡ÌËˇ\n", key);
	printf("¬‚Â‰ËÚÂ Î˛·ÓÂ ‰Û„ÓÂ ˜ËÒÎÓ ‰Îˇ Á‡ÔÛÒÍ‡ ·ÂÁ ÚÂÒÚËÓ‚‡ÌËˇ\n");
	printf("ŒÊË‰‡ÌËÂ ‚‚Ó‰‡... ");
=======
	printf("–í–≤–µ–¥–∏—Ç–µ –∫–ª—é—á %d –¥–ª—è –ø–æ–¥—Ç–≤–µ—Ä–∂–¥–µ–Ω–∏—è –Ω–∞—á–∞–ª–∞ —Ç–µ—Å—Ç–æ–≤: ", key);
>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
	scanf("%d", &input);
	if (input == key)
	{
		test();
	}
	else
	{
		system("cls");
	}
}

bool test()
{
	clearTextFile();
	printf("–ü—Ä–æ–≤–æ–¥–∏–º —Ç–µ—Å—Ç—ã!\n");

	Contact contactsMenuBufferTest[BOOK_SIZE];
	int addCounter = 0;
	char* name = "name";
	char* phone = "8888";

	strcpy(contactsMenuBufferTest[0].name, name);
	strcpy(contactsMenuBufferTest[0].phone, phone);
	saveData(contactsMenuBufferTest, 1);
	printAll(); // –Ω–µ —É–ø–∞–ª–æ -> ok =)

	Contact contactsFileBufferTest[BOOK_SIZE];
	if (readFromFile(contactsFileBufferTest) != 2)
	{
		printf("–û—à–∏–±–∫–∞ –≤ readFromFile()! –ù–µ–≤–µ—Ä–Ω–æ —Å—á–∏—Ç–∞—é—Ç—Å—è —Å—Ç—Ä–æ–∫–∏!\n");
		printf("–û–∂–∏–¥–∞–ª—Å—è –æ—Ç–≤–µ—Ç 2, –ø–æ–ª—É—á–µ–Ω–Ω—ã–π: %d\n", readFromFile(contactsFileBufferTest));
		return false;
	}
	if (strcmp(contactsFileBufferTest[0].name, name) != 0 || strcmp(contactsFileBufferTest[0].phone, phone) != 0)
	{
<<<<<<< HEAD
		printf("Œ¯Ë·Í‡ ‚ readFromFile()!\n");
		printf("ŒÊË‰‡ÎÒˇ ÓÚ‚ÂÚ name 8888, ÔÓÎÛ˜ÂÌÌ˚È: %s %s\n", contactsFileBufferTest[0].name, contactsFileBufferTest[0].phone);
		return false;
	}

	if (strcmp(getName(phone), name) != 0)
	{
		printf("Œ¯Ë·Í‡ ‚ getName()!\n");
		printf("ŒÊË‰‡ÎÒˇ ÓÚ‚ÂÚ name, ÔÓÎÛ˜ÂÌÌ˚È: %s\n", getName(phone));
		return false;
	}

	if (strcmp(getPhoneNumber(name), phone) != 0)
	{
		printf("Œ¯Ë·Í‡ ‚ getPhoneNumber()!\n");
		printf("ŒÊË‰‡ÎÒˇ ÓÚ‚ÂÚ 8888, ÔÓÎÛ˜ÂÌÌ˚È: %s\n", getPhoneNumber(name));
=======
		printf("–û—à–∏–±–∫–∞ –≤ readFromFile()!\n –ù–µ–≤–µ—Ä–Ω–æ —Å—á–∏—Ç—ã–≤–∞—é—Ç—Å—è –¥–∞–Ω–Ω—ã–µ!\n");
		printf("–û–∂–∏–¥–∞–ª—Å—è –æ—Ç–≤–µ—Ç name 8888, –ø–æ–ª—É—á–µ–Ω–Ω—ã–π: %s %s\n", contactsFileBufferTest[0].name, contactsFileBufferTest[0].phone);
>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
		return false;
	}
	
	system("cls");
	printf("–¢–µ—Å—Ç—ã –ø—Ä–æ–π–¥–µ–Ω—ã!\n");
	clearTextFile();
	return true;
}

void clearTextFile()
{
	FILE *file = fopen("phonebook.txt", "w");
	fclose(file);
}
