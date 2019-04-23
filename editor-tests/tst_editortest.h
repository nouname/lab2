#pragma once

#include <limits.h>
#include <string.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
    #include "../app/text/_text.h"
    #include "../app/text/text.h"
    #include "../app/common.h"
}

static void driver(int index, char *contents, int cursor, void *data);

static void driver(int index, char *contents, int cursor, void *data) {
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    assert(contents != NULL);
}

using namespace testing;

TEST(checkMem, editortests)
{
    EXPECT_NE(create_objects(), nullptr);
}

TEST(noSuchFile, editortests)
{
    text txt = create_text();
    load(txt, "<filename>");

    EXPECT_EQ(txt->length, 0);
}

TEST(accessError, editortests)
{
    text txt = create_text();
    load(txt, "/etc/shadow");

    EXPECT_EQ(txt->length, 0);
}

TEST(showText, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    show(txt);
    shownum(txt);

    EXPECT_EQ(txt->cursor->position, 5);
}

TEST(showEmptyText, editortests)
{
    text txt = create_text();
    show(txt);
    shownum(txt);

    EXPECT_EQ(txt->cursor->position, 0);
}

TEST(saveError, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");

    EXPECT_NE(txt->length, 0);
    save(txt, "test.txt");
    EXPECT_NE(fopen("test.txt", "r"), nullptr);
}

TEST(normalTextAppend, editortests)
{
    text txt = create_text();
    const char* contents = "TEST";
    load(txt, "input.txt");

    EXPECT_NO_FATAL_FAILURE(append_line(txt, contents););
    EXPECT_NE(txt->length, 0);
}

TEST(tooLongTextAppend, editortests)
{
    text txt = create_text();
    char contents[10000];
    load(txt, "input.txt");
    for (; strlen(contents) < 10000; strcat(contents, "TEST"));

    EXPECT_EXIT(append_line(txt, contents), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}

TEST(cursorToExistingPos, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwcrsr(txt, 0, 2);

    EXPECT_EQ(txt->cursor->position, 1);
}

TEST(cursorToNotExistingPos, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwcrsr(txt, -1, -1);

    EXPECT_EQ(txt->cursor->position, 0);
}

TEST(deleteLines, editortests)
{
    text txt = create_text();
    load(txt, "long.txt");
    delete_line(txt, 3);

    EXPECT_EQ(txt->length, 2);
    delete_line(txt, 1);
    EXPECT_EQ(txt->length, 1);
}

TEST(deleteHigher, editortests)
{
    text txt = create_text();
    load(txt, "long.txt");
    delete_line(txt, 2);

    EXPECT_EQ(txt->length, 2);
}

TEST(deleteNotExistingLine, editortests)
{
    text txt = create_text();
    load(txt, "long.txt");

    EXPECT_DEATH(delete_line(txt, 10), "");
    EXPECT_DEATH(delete_line(txt, -1), "");
}

TEST(deleteLineFromEmptyText, editortests)
{
    text txt = create_text();
    delete_line(txt, 1);

    EXPECT_EQ(txt->begin, nullptr);
    EXPECT_EQ(txt->end, nullptr);
}

TEST(deleteFromOneLineText, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    delete_line(txt, 1);

    EXPECT_EQ(txt->begin, nullptr);
    EXPECT_EQ(txt->end, nullptr);
}

TEST(removeAll, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    remove_all(txt);

    EXPECT_NE(txt, nullptr);
    EXPECT_EQ(txt->length, 0);
}

TEST(removeAllFromEmptyText, editortests)
{
    text txt = nullptr;
    remove_all(txt);

    EXPECT_EQ(txt, nullptr);
}

TEST(cursorToEndOfLine, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mle(txt);

    EXPECT_EQ(txt->cursor->position, 4);
}

TEST(cursorToBeginOfWord, editortests)
{
    text txt = create_text();
    load(txt, "input.txt");
    mwbb(txt);

    EXPECT_EQ(txt->cursor->position, 0);
}

TEST(textProcessing, editortests) {
    text txt = create_text();
    load(txt, "input.txt");

    process_forward(txt, driver, NULL);
    EXPECT_NO_FATAL_FAILURE(process_forward(txt, driver, NULL););
}
