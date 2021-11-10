/* syntaxhighlighter.cpp
 * implements syntax highlighting of Java code */

#include "syntaxhighlighter.h"
#include "settingsmanager.h"

/* set up the highlighting */
Highlighter::Highlighter(QTextDocument* parent)
    : QSyntaxHighlighter(parent) {
    HighlightingRule rule;

    /* types */
    typeFormat.setForeground(SettingsManager::types());
    QStringList typePatterns;
    typePatterns << "\\bbyte\\b"
                 << "\\bshort\\b"
                 << "\\bint\\b"
                 << "\\blong\\b"
                 << "\\bfloat\\b"
                 << "\\bdouble\\b"
                 << "\\bboolean\\b"
                 << "\\bchar\\b"
                 << "\\bshort\\b"
                 << "\\bvoid\\b"
                 << "\\bString\\b";
    foreach (const QString& pattern, typePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = typeFormat;
        highlightingRules.append(rule);
    }

    /* keywords */
    keywordFormat.setForeground(SettingsManager::keywords());
    QStringList keywordPatterns;
    keywordPatterns << "\\babstract\\b"
                    << "\\bassert\\b"
                    << "\\bbreak\\b"
                    << "\\bcase\\b"
                    << "\\bcatch\\b"
                    << "\\bclass\\b"
                    << "\\bcontinue\\b"
                    << "\\bdefault\\b"
                    << "\\bdo\\b"
                    << "\\belse\\b"
                    << "\\benum\\b"
                    << "\\bextends\\b"
                    << "\\bfinal\\b"
                    << "\\bfinally\\b"
                    << "\\bfor\\b"
                    << "\\bif\\b"
                    << "\\bimplements\\b"
                    << "\\bimport\\b"
                    << "\\binstanceof\\b"
                    << "\\binterface\\b"
                    << "\\bnative\\b"
                    << "\\bnew\\b"
                    << "\\bpackage\\b"
                    << "\\bprivate\\b"
                    << "\\bprotected\\b"
                    << "\\bpublic\\b"
                    << "\\breturn\\b"
                    << "\\bstatic\\b"
                    << "\\bstrictfp\\b"
                    << "\\bsuper\\b"
                    << "\\bswitch\\b"
                    << "\\bsynchronized\\b"
                    << "\\bthis\\b"
                    << "\\bthrow\\b"
                    << "\\bthrows\\b"
                    << "\\btransient\\b"
                    << "\\btry\\b"
                    << "\\bvolatile\\b"
                    << "\\bwhile\\b";

    foreach (const QString& pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    /* values */
    valueFormat.setForeground(SettingsManager::values());
    QStringList valuePatterns;
    valuePatterns << "\\btrue\\b"
                  << "\\bfalse\\b"
                  << "[0-9]\\d{0,3}"
                  << "\\d.\\d";
    foreach (const QString& pattern, valuePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = valueFormat;
        highlightingRules.append(rule);
    }

    /* strings */
    quotationFormat.setForeground(SettingsManager::values());
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    /* single-line comments */
    singleLineCommentFormat.setForeground(SettingsManager::comments());
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    /* multi-line comments 
     * FIXME - this doesn't currently work! */
    multiLineCommentFormat.setForeground(SettingsManager::comments());
    rule.pattern = QRegExp("\\/\\*(\\r|[^*]|\\n|(\\*+[^\\/]))*\\*\\/");
    rule.format = multiLineCommentFormat;
    highlightingRules.append(rule);
}

void Highlighter::highlightBlock(const QString& text) {
    foreach (const HighlightingRule& rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}
