/*
 * FBReader -- electronic book reader
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __TEXTSTYLE_H__
#define __TEXTSTYLE_H__

#include <map>
#include <string>

#include <abstract/shared_ptr.h>

#include <abstract/ZLOptions.h>

#include "../model/TextKind.h"
#include "../model/AlignmentType.h"

class TextStyle {

protected:
  TextStyle();

public:
  virtual ~TextStyle();

  virtual bool isDecorated() const = 0;

  virtual const std::string &fontFamily() const = 0;
  virtual int fontSize() const = 0;

  virtual bool bold() const = 0;
  virtual bool italic() const = 0;

  virtual ZLColor color() const = 0;

  virtual int spaceBefore() const = 0;
  virtual int spaceAfter() const = 0;
  virtual int leftIndent() const = 0;
  virtual int rightIndent() const = 0;
  virtual int firstLineIndentDelta() const = 0;
  virtual int verticalShift() const = 0;
  virtual AlignmentType alignment() const = 0;
  virtual double lineSpace() const = 0;

  virtual bool allowHyphenations() const = 0;
};

typedef shared_ptr<TextStyle> TextStylePtr;

class BaseTextStyle : public TextStyle {

public:
  BaseTextStyle(const std::string &fontFamily, int fontSize);

  bool isDecorated() const;

  const std::string &fontFamily() const;

  int fontSize() const;
  bool bold() const;
  bool italic() const;

  ZLColor color() const;

  int spaceBefore() const;
  int spaceAfter() const;
  int leftIndent() const;
  int rightIndent() const;
  int firstLineIndentDelta() const;
  int verticalShift() const;

  AlignmentType alignment() const;

  double lineSpace() const;

  bool allowHyphenations() const;

public:
  ZLIntegerRangeOption LeftMarginOption;
  ZLIntegerRangeOption RightMarginOption;
  ZLIntegerRangeOption TopMarginOption;
  ZLIntegerRangeOption BottomMarginOption;

  ZLColorOption BackgroundColorOption;
  ZLColorOption SelectedTextColorOption;
  ZLColorOption RegularTextColorOption;
  ZLColorOption HyperlinkTextColorOption;
  ZLColorOption TreeLinesColorOption;

  ZLBooleanOption AutoHyphenationOption;

  ZLStringOption FontFamilyOption;
  ZLIntegerRangeOption FontSizeOption;
  ZLBooleanOption BoldOption;
  ZLBooleanOption ItalicOption;
  ZLIntegerOption AlignmentOption;
  ZLDoubleOption LineSpaceOption;
};

class TextStyleDecoration {

public:
  TextStyleDecoration(const std::string &name, int fontSizeDelta, Boolean3 bold, Boolean3 italic, int verticalShift, Boolean3 allowHyphenations);
  virtual ~TextStyleDecoration();

  virtual bool isFullDecoration() const;

  virtual TextStylePtr createDecoratedStyle(const TextStylePtr base) const;

  const std::string &name() const;

  bool isHyperlinkStyle() const;
  void setHyperlinkStyle();

public:
  ZLStringOption FontFamilyOption;
  ZLIntegerRangeOption FontSizeDeltaOption;
  ZLBoolean3Option BoldOption;
  ZLBoolean3Option ItalicOption;

  ZLIntegerOption VerticalShiftOption;

  ZLBoolean3Option AllowHyphenationsOption;

private:
  std::string myName;

  bool myIsHyperlinkStyle;
};

class FullTextStyleDecoration : public TextStyleDecoration {

public:
  FullTextStyleDecoration(const std::string &name, int fontSizeDelta, Boolean3 bold, Boolean3 italic, int spaceBefore, int spaceAfter, int leftIndent, int rightIndent, int firstLineIndentDelta, int verticalShift, AlignmentType alignment, double lineSpace, Boolean3 allowHyphenations);
  ~FullTextStyleDecoration();

  virtual bool isFullDecoration() const;

  TextStylePtr createDecoratedStyle(const TextStylePtr base) const;

public:
  ZLIntegerRangeOption SpaceBeforeOption;
  ZLIntegerRangeOption SpaceAfterOption;
  ZLIntegerRangeOption LeftIndentOption;
  ZLIntegerRangeOption RightIndentOption;
  ZLIntegerRangeOption FirstLineIndentDeltaOption;

  ZLIntegerOption AlignmentOption;

  ZLDoubleOption LineSpaceOption;
};

class DecoratedTextStyle : public TextStyle {

protected:
  DecoratedTextStyle(const TextStylePtr base);

public:
  virtual ~DecoratedTextStyle();

  bool isDecorated() const;
  const TextStylePtr base() const;

private:
  const TextStylePtr myBase;
};

class ForcedControlEntry;

class ForcedTextStyle : public DecoratedTextStyle {

public:
  ForcedTextStyle(TextStylePtr base, const ForcedControlEntry &entry);
  ~ForcedTextStyle();

  const std::string &fontFamily() const;
  int fontSize() const;

  bool bold() const;
  bool italic() const;

  ZLColor color() const;

  int spaceBefore() const;
  int spaceAfter() const;
  int leftIndent() const;
  int rightIndent() const;
  int firstLineIndentDelta() const;
  int verticalShift() const;
  AlignmentType alignment() const;
  double lineSpace() const;

  bool allowHyphenations() const;

private:
  const ForcedControlEntry &myEntry;
};

class PartialDecoratedTextStyle : public DecoratedTextStyle {

private:
  PartialDecoratedTextStyle(const TextStylePtr base, const TextStyleDecoration &decoration);
  friend TextStylePtr TextStyleDecoration::createDecoratedStyle(const TextStylePtr base) const;

public:
  virtual ~PartialDecoratedTextStyle();
  const std::string &fontFamily() const;
  int fontSize() const;
  bool bold() const;
  bool italic() const;

  ZLColor color() const;

  int spaceBefore() const;
  int spaceAfter() const;
  int leftIndent() const;
  int rightIndent() const;
  int firstLineIndentDelta() const;
  int verticalShift() const;

  AlignmentType alignment() const;
  bool allowHyphenations() const;

  double lineSpace() const;

private:
  const TextStyleDecoration &myDecoration;
};

class FullDecoratedTextStyle : public DecoratedTextStyle {

private:
  FullDecoratedTextStyle(const TextStylePtr base, const FullTextStyleDecoration &decoration);
  friend TextStylePtr FullTextStyleDecoration::createDecoratedStyle(const TextStylePtr base) const;

public:
  ~FullDecoratedTextStyle();
  const std::string &fontFamily() const;
  int fontSize() const;
  bool bold() const;
  bool italic() const;

  ZLColor color() const;

  int spaceBefore() const;
  int spaceAfter() const;
  int leftIndent() const;
  int rightIndent() const;
  int firstLineIndentDelta() const;
  int verticalShift() const;

  AlignmentType alignment() const;
  bool allowHyphenations() const;

  double lineSpace() const;

private:
  const FullTextStyleDecoration &myDecoration;
};

class PositionIndicatorStyle {

public:
  ZLBooleanOption ShowOption;
  ZLBooleanOption IsSensitiveOption;
  ZLColorOption ColorOption;
  ZLIntegerRangeOption HeightOption;
  ZLIntegerRangeOption OffsetOption;

public:
  PositionIndicatorStyle();
};

class TextStyleCollection {

public:
  static TextStyleCollection &instance();
  static void deleteInstance();

  TextStylePtr baseStylePtr() const;
  BaseTextStyle &baseStyle() const;
  TextStyleDecoration *decoration(TextKind kind) const;
  PositionIndicatorStyle &indicatorStyle();

private:
  TextStyleCollection();
  ~TextStyleCollection();

private:
  static TextStyleCollection *ourInstance;
  
private:
  TextStylePtr myBaseStyle;
  PositionIndicatorStyle myIndicatorStyle;
  std::map<TextKind,TextStyleDecoration*> myDecorationMap;

friend class StyleReader;
};

inline TextStyle::TextStyle() {}
inline TextStyle::~TextStyle() {}

inline bool BaseTextStyle::isDecorated() const { return false; }
inline const std::string &BaseTextStyle::fontFamily() const { return FontFamilyOption.value(); }
inline int BaseTextStyle::fontSize() const { return FontSizeOption.value(); }
inline bool BaseTextStyle::bold() const { return BoldOption.value(); }
inline bool BaseTextStyle::italic() const { return ItalicOption.value(); }
inline int BaseTextStyle::spaceBefore() const { return 0; }
inline int BaseTextStyle::spaceAfter() const { return 0; }
inline int BaseTextStyle::leftIndent() const { return 0; }
inline int BaseTextStyle::rightIndent() const { return 0; }
inline int BaseTextStyle::firstLineIndentDelta() const { return 0; }
inline int BaseTextStyle::verticalShift() const { return 0; }
inline AlignmentType BaseTextStyle::alignment() const { return (AlignmentType)AlignmentOption.value(); }
inline double BaseTextStyle::lineSpace() const { return LineSpaceOption.value(); }
inline bool BaseTextStyle::allowHyphenations() const { return true; }

inline TextStyleDecoration::~TextStyleDecoration() {}
inline bool TextStyleDecoration::isFullDecoration() const { return false; }
inline const std::string &TextStyleDecoration::name() const { return myName; }
inline bool TextStyleDecoration::isHyperlinkStyle() const { return myIsHyperlinkStyle; }
inline void TextStyleDecoration::setHyperlinkStyle() { myIsHyperlinkStyle = true; }

inline FullTextStyleDecoration::~FullTextStyleDecoration() {}
inline bool FullTextStyleDecoration::isFullDecoration() const { return true; }

inline DecoratedTextStyle::DecoratedTextStyle(const TextStylePtr base) : myBase(base) {}
inline DecoratedTextStyle::~DecoratedTextStyle() {}
inline bool DecoratedTextStyle::isDecorated() const { return true; }
inline const TextStylePtr DecoratedTextStyle::base() const { return myBase; }

inline ForcedTextStyle::ForcedTextStyle(TextStylePtr base, const ForcedControlEntry &entry) : DecoratedTextStyle(base), myEntry(entry) {}
inline ForcedTextStyle::~ForcedTextStyle() {}
inline const std::string &ForcedTextStyle::fontFamily() const { return base()->fontFamily(); }
inline int ForcedTextStyle::fontSize() const { return base()->fontSize(); }
inline bool ForcedTextStyle::bold() const { return base()->bold(); }
inline bool ForcedTextStyle::italic() const { return base()->italic(); }
inline ZLColor ForcedTextStyle::color() const { return base()->color(); }
inline int ForcedTextStyle::spaceBefore() const { return base()->spaceBefore(); }
inline int ForcedTextStyle::spaceAfter() const { return base()->spaceAfter(); }
inline int ForcedTextStyle::firstLineIndentDelta() const { return base()->firstLineIndentDelta(); }
inline int ForcedTextStyle::verticalShift() const { return base()->verticalShift(); }
inline double ForcedTextStyle::lineSpace() const { return base()->lineSpace(); }
inline bool ForcedTextStyle::allowHyphenations() const { return base()->allowHyphenations(); }

inline PartialDecoratedTextStyle::PartialDecoratedTextStyle(const TextStylePtr base, const TextStyleDecoration &decoration) : DecoratedTextStyle(base), myDecoration(decoration) {}
inline PartialDecoratedTextStyle::~PartialDecoratedTextStyle() {}
inline int PartialDecoratedTextStyle::spaceBefore() const { return base()->spaceBefore(); }
inline int PartialDecoratedTextStyle::spaceAfter() const { return base()->spaceAfter(); }
inline int PartialDecoratedTextStyle::leftIndent() const { return base()->leftIndent(); }
inline int PartialDecoratedTextStyle::rightIndent() const { return base()->rightIndent(); }
inline int PartialDecoratedTextStyle::firstLineIndentDelta() const { return base()->firstLineIndentDelta(); }
inline int PartialDecoratedTextStyle::verticalShift() const { return base()->verticalShift() + myDecoration.VerticalShiftOption.value(); }
inline AlignmentType PartialDecoratedTextStyle::alignment() const { return base()->alignment(); }
inline double PartialDecoratedTextStyle::lineSpace() const { return base()->lineSpace(); }

inline FullDecoratedTextStyle::FullDecoratedTextStyle(const TextStylePtr base, const FullTextStyleDecoration &decoration) : DecoratedTextStyle(base), myDecoration(decoration) {}
inline FullDecoratedTextStyle::~FullDecoratedTextStyle() {}
inline int FullDecoratedTextStyle::spaceBefore() const { return myDecoration.SpaceBeforeOption.value(); }
inline int FullDecoratedTextStyle::spaceAfter() const { return myDecoration.SpaceAfterOption.value(); }
inline int FullDecoratedTextStyle::leftIndent() const { return base()->leftIndent() + myDecoration.LeftIndentOption.value(); }
inline int FullDecoratedTextStyle::rightIndent() const { return base()->rightIndent() + myDecoration.RightIndentOption.value(); }
inline int FullDecoratedTextStyle::verticalShift() const { return base()->verticalShift() + myDecoration.VerticalShiftOption.value(); }
inline double FullDecoratedTextStyle::lineSpace() const { double space = myDecoration.LineSpaceOption.value(); return (space == 0) ? base()->lineSpace() : space; }

inline TextStylePtr TextStyleCollection::baseStylePtr() const { return myBaseStyle; }
inline BaseTextStyle &TextStyleCollection::baseStyle() const { return (BaseTextStyle&)*myBaseStyle; }
inline PositionIndicatorStyle &TextStyleCollection::indicatorStyle() { return myIndicatorStyle; }

#endif /* __TEXTSTYLE_H__ */
