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

#include <olp/core/client/HRN.h>
#include <olp/core/client/OlpClientSettings.h>
#include <olp/dataservice/read/Types.h>

namespace olp {
namespace dataservice {
namespace read {

class StreamLayerClientImpl {
 public:
  StreamLayerClientImpl(client::HRN catalog, std::string layer_id,
                        client::OlpClientSettings settings);

  virtual ~StreamLayerClientImpl();

 private:
  client::HRN catalog_;
  std::string layer_id_;
  client::OlpClientSettings settings_;
};

}  // namespace read
}  // namespace dataservice
}  // namespace olp