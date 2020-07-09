/*
 * Copyright (C) 2020 HERE Europe B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 * License-Filename: LICENSE
 */

#pragma once

#include "olp/core/cache/DefaultCache.h"

#include <set>
#include <string>

namespace olp {
namespace cache {

class ProtectedData {
 public:
  using ProtectedKeyChanged = std::function<void(const std::string&)>;

  ProtectedData();

  ~ProtectedData();

  bool Protect(const DefaultCache::KeyListType& keys,
               const ProtectedKeyChanged& change_key_to_protected);

  bool Release(const DefaultCache::KeyListType& keys,
               const ProtectedKeyChanged& released_key_from_protected);

  bool ReadListOfProtectedKeys(KeyValueCache::ValueTypePtr value);

  KeyValueCache::ValueTypePtr WriteListOfProtectedKeys();

  bool IsProtected(const std::string& key) const;

 private:
  bool IsPrefix(const std::string& prefix, const std::string& key) const;

  bool IsEqualOrPrefix(const std::string& prefix, const std::string& key) const;
  // custom comparator needed to reduce duplicates for keys, which are already
  // protected by prefix
  struct CustomCompare {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
      if (rhs.length() < lhs.length()) {
        if (std::equal(rhs.begin(), rhs.end(), lhs.begin())) {
          return false;
        }
      } else if (lhs.length() < rhs.length()) {
        if (std::equal(lhs.begin(), lhs.end(), rhs.begin())) {
          return false;
        }
      }
      return lhs < rhs;
    }
  };
  std::set<std::string, CustomCompare> protected_data_;
};

}  // namespace cache
}  // namespace olp